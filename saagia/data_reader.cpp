#include "data_reader.h"
#include "data_structures.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QStringList>
#include <QNetworkReply>
#include <QVariant>
#include <QByteArray>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QXmlStreamReader>
#include <map>

Data_reader::Data_reader(std::shared_ptr<Data_structures> data_structures, QObject *parent) :
    QObject( parent ),
    data_structures_{ data_structures },
    network_{ new QNetworkAccessManager(this) },
    currentUrl_( "" ),
    currentStatuscode_{ 0 },
    currentContent_{ "" },
    data_type_{ 0 }
{
    // connect the "finished" signal from the network to the requestCompleted function
    connect(network_, &QNetworkAccessManager::finished, this, &Data_reader::requestCompleted);
}

Data_reader::~Data_reader()
{
    delete network_;
}

QUrl Data_reader::getCurrentUrl() const
{
    return currentUrl_;
}

int Data_reader::getCurrentStatuscode() const
{
    return currentStatuscode_;
}

QString Data_reader::getCurrentContent() const
{
    return currentContent_;
}

void Data_reader::requestUrl(const QString &url, const QString &header)
{
    if (url == "")
    {
        return;
    }

    QNetworkRequest request{ url };

    // the header parameter is assumed to be in format "<header_name>:<header_value>"
    header_ = header;
    if (header != "")
    {
        QStringList headerParts{ header.split(":") };
        if (headerParts.length() == 2)
        {
            QString headerName{ headerParts[0] };
            QString headerValue{ headerParts[1] };
            if (headerName != "" && headerValue != "")
            {
                // set the header and its value to the request
                request.setRawHeader(headerName.toUtf8(), headerValue.toUtf8());
            }
        }
    }

    // connect a network error signal to the requestError function
    QNetworkReply* networkReply{ network_->get(request) };
    connect(
        networkReply,
        #if (QT_VERSION >= QT_VERSION_CHECK(5, 15, 0))
            QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::errorOccurred),
        #else
            QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
        #endif
        this,
        &Data_reader::requestError
    );

    qDebug() << "Request:" << request.url() << "headers:" << request.rawHeaderList();
}

void Data_reader::set_data_type(int data_type)
{
    data_type_ = data_type;
    qDebug() << "data reader test print for data type" << data_type_;
}

void Data_reader::requestCompleted(QNetworkReply *networkReply)
{
    currentUrl_ = networkReply->url();
    emit currentUrlChanged();

    QVariant statuscodeVariant{ networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute) };
    currentStatuscode_ = statuscodeVariant.toInt();
    emit currentStatuscodeChanged();

    QByteArray responseContent{ networkReply->readAll() };
    currentContent_ = QString(responseContent);
    // normally the parsing of the response would be done here, in this case just show the raw content
    //emit currentContentChanged();
    //model_->set_new_data_content(currentContent_);
    if (header_ != "") {
        parseJson(currentContent_);
    }
    else {
        parseXML(currentContent_);
    }
   // parseXML(currentContent_);
   // parseJson(currentContent_);
    qDebug() << "Reply to" << networkReply->url() << "with status code:" << statuscodeVariant.toInt();

}


void Data_reader::requestError(QNetworkReply::NetworkError errorCode)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    qDebug() << "Received error:" << errorCode << "for url:" << reply->url();
}

void Data_reader::parseJson(QString content)
{
    //model_->clear_database();
    data_structures_->clear_data_structures();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(content.toUtf8());

    // qDebug() << jsonResponse;

    QJsonArray jsonArray = jsonResponse.array();


    foreach (const QJsonValue & value, jsonArray) {

        QJsonObject obj = value.toObject();
        int kvalue = (obj["value"].toInt());

        QString start_time = (obj["start_time"].toString());
        QString end_time = (obj["end_time"].toString());

        //model_->save_to_map(start_time, kvalue);
        data_structures_->append_energy_data(start_time, data_type_, kvalue);
    }
    data_structures_->test_print();
    //model_->set_chart_data();
}

void Data_reader::parseXML(QString content)
{
    QXmlStreamReader reader(content);
    // bool type_exists;
    QString latest_type;
    QString time = "";
    QString temp;
    QString w_speed;
    QString cloudines;
    weather_data data;

    while (!reader.atEnd()) {
        //In the XML there are allways forst "Time", then "ParameterName" and finally "ParameterValue"
        //in this order for one specific point of data
        if (reader.name() == "Time"){
            QString next_time = reader.readElementText();
            //First time point is handled separately
            if (time == "") {
                time = next_time;
            }
            //when time advances, weather data for old time point is transferred and saved
            if (next_time != time) {
                data.temperature = temp.toFloat();
                data.wind_speed = w_speed.toFloat();
                data.cloudines = cloudines;
                qDebug() << "Tallennan sään: lämpö" << temp << " tuuli: " << w_speed << " pilvi: " << cloudines;
                data_structures_->append_weather_data(time, data);
                time = next_time;
            }

        }       
        else if (reader.name() == "ParameterName"){
            latest_type = reader.readElementText();
        }
        //ParameterValue can be either temperature, wind speed or cloudines
        else if (reader.name() == "ParameterValue"){
            QString value = reader.readElementText();
            //Temperature
            if (latest_type == "t2m") {
                temp = value;
            }
            //Wind speed
            else if (latest_type == "ws_10min") {
                w_speed = value;
            }
            //Cloudines
            else if (latest_type == "n_man") {
                cloudines = value;
            }
        }
        reader.readNext();
    }
}



