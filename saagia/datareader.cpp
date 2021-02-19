#include "datareader.h"

DataReader::DataReader()
{

}

QString DataReader::getData()
{
    readData();
    return data_;
}

void DataReader::readData()
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &DataReader::finish);
    const QUrl url = QUrl(myURL);
    QNetworkRequest request;
    request.setRawHeader("x-api-key", myAPIKey);
    man->get(request);

   // finish(man->get(requ));
}

void DataReader::finish(QNetworkReply *reply)
{
    data_ = reply->readAll(); //Downloaded content is stored in this variable for the time being
    qDebug() << "Tietojen haku onnistui";
}


