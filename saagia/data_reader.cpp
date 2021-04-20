#include "data_reader.h"

Data_reader::Data_reader(std::shared_ptr<Data_structures> data_structures, QObject *parent) :
    QObject( parent ),
    data_structures_{ data_structures },
    network_{ new QNetworkAccessManager(this) },
    currentUrl_( "" ),
    currentStatuscode_{ 0 },
    currentContent_{ "" },
    data_type_{ 0 }
{
    // Connect the "finished" signal from the network to the requestCompleted function
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

    qDebug() << "url: " << url << "header: " << header;

    if ( url == "" ) {
        return;
    }

    QNetworkRequest request{ url };
    // The header parameter is assumed to be in format
    // "<header_name>:<header_value>"
    header_ = header;
    if ( header != "" ) {
        QStringList headerParts{ header.split(":") };
        if ( headerParts.length() == 2 ) {
            QString headerName{ headerParts[0] };
            QString headerValue{ headerParts[1] };
            if ( headerName != "" && headerValue != "" ) {
                // set the header and its value to the request
                request.setRawHeader(headerName.toUtf8(), headerValue.toUtf8());
            }
        }
    }

    // Connect a network error signal to the requestError function
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
    qDebug() << "Request finished";
    currentUrl_ = networkReply->url();
    emit currentUrlChanged();

    QVariant statuscodeVariant{ networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute) };
    currentStatuscode_ = statuscodeVariant.toInt();
    emit currentStatuscodeChanged();

    QByteArray responseContent{ networkReply->readAll() };
    currentContent_ = QString(responseContent);
    // Normally the parsing of the response would be done here, in this case
    // just show the raw content

    //emit currentContentChanged();

    if ( header_ != "" ) {
        parseJson(currentContent_);
    }
    else {
        parseXML(currentContent_);
    }
    qDebug() << "Reply to" << networkReply->url()
             << "with status code:" << statuscodeVariant.toInt();

}

void Data_reader::requestError(QNetworkReply::NetworkError errorCode)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    qDebug() << "Received error:" << errorCode << "for url:" << reply->url();
}


QString Data_reader::parsedData(int energy_type)
{

    std::map<int, std::map<QString, int>> data = data_structures_->get_energy_structure();
    std::map<int, std::map<QString, int>>::iterator iter = data.find(energy_type);
    QString parsed;
    QJsonArray arr;
    parsed.append(QString::number(data_type_) + "\n");
    std::map<QString, int>::iterator it = iter->second.begin();
    while ( it != iter->second.end() ) {

        QJsonObject obj;
        obj.insert("start_time", it->first);
        obj.insert("value", it->second);
        arr.push_back(obj);
        it++;
    }

    QJsonDocument doc;
    doc.setArray(arr);
    parsed.append(doc.toJson(QJsonDocument::Compact));
    qDebug() << parsed;
    return parsed;
}

void Data_reader::parseJson(QString content)
{

    QJsonDocument jsonResponse = QJsonDocument::fromJson(content.toUtf8());

    // qDebug() << jsonResponse;

    QJsonArray jsonArray = jsonResponse.array();


    foreach (const QJsonValue & value, jsonArray) {

        QJsonObject obj = value.toObject();
        int kvalue = (obj["value"].toDouble());

        QString start_time = (obj["start_time"].toString());
        QString end_time = (obj["end_time"].toString());

        //model_->save_to_map(start_time, kvalue);
        data_structures_->append_energy_data(start_time, data_type_, kvalue);
    }
    data_structures_->test_print();
    //model_->set_chart_data();



    data_structures_->test_print();

    // PIIRTO TÄHÄN KOHTAAN!
    //model_->set_chart_data();
}

void Data_reader::parseXML(QString content)
{
    QXmlStreamReader reader(content);

    QString latest_type;
    QString time = "";
    float temp = NO_VALUE;
    float w_speed = NO_VALUE;
    float cloudiness = NO_VALUE;
    float max_temp = NO_VALUE;
    float min_temp = NO_VALUE;

    while ( !reader.atEnd() ) {
        // In the XML there are always first "Time", then "ParameterName" and
        // finally "ParameterValue" in this order for one specific point of data
        if ( reader.name() == "Time" ) {
            QString next_time = reader.readElementText();

            //First time point is handled separately
            if ( time == "" ) {
                time = next_time;
            }
            // When time advances, weather data for old time point
            // is transferred and saved
            if ( next_time != time ) {
                //
                qDebug() << time;
                data_structures_->append_weather_data(
                            time,
                            {temp, w_speed, cloudiness, max_temp, min_temp});
                time = next_time;
                temp = NO_VALUE;
                w_speed = NO_VALUE;
                cloudiness = NO_VALUE;
                max_temp = NO_VALUE;
                min_temp = NO_VALUE;
            }

        }       
        else if ( reader.name() == "ParameterName" ) {
            latest_type = reader.readElementText();
        }
        // ParameterValue can be either temperature, wind speed, cloudiness,
        // minimum temperature or maximum temperature
        else if ( reader.name() == "ParameterValue" ) {
            QString XMLvalue = reader.readElementText();
            float value;
            if ( XMLvalue == "NaN" ) {
                value = NO_VALUE;
            }
            else {
                value = XMLvalue.toFloat();
            }

            // Temperature
            if ( latest_type == "t2m" || latest_type == "Temperature" ||
                 latest_type == "tday" ) {
                temp = value;
            }
            // Wind speed
            else if ( latest_type == "ws_10min" ||
                      latest_type == "WindSpeedMS" ) {
                w_speed = value;
            }
            // Cloudiness
            else if ( latest_type == "n_man" ) {
                cloudiness = value;
            }
            // Maximum temperature of the day
            else if ( latest_type == "tmax" ) {
                max_temp = value;
            }
            // Minimum temperature of the day
            else if ( latest_type == "tmin" ) {
                min_temp = value;
            }
        }
        reader.readNext();
    }
}
