#include "datareader.h"

DataReader::DataReader()
{

}

void DataReader::readData()
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &DataReader::finish);
    const QUrl url = QUrl(myURL);
    QNetworkRequest requ(url);
   //finish(man->get(requ));
}

void DataReader::finish(QNetworkReply *reply)
{
    QString text = reply->readAll(); //Downloaded content is stored in this variable for the time being

}


