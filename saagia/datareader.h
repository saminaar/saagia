#ifndef DATAREADER_H
#define DATAREADER_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>

class DataReader: public QMainWindow
{
    Q_OBJECT
public:
    DataReader();
    QString getData();
public slots:
    void readData();

private:
    QString myURL =
            "http://opendata.fmi.fi/wfs?service=WFS&version=2.0.0&request=describeStoredQueries"; //Page containig FMI API-info in xml
    QNetworkRequest::KnownHeaders header;
    QByteArray myAPIKey = "stwnenddFW4GqId8Hr9Hx8dfRV70APsuaW2LCWq3";
    QString data_;

private slots:
    void finish(QNetworkReply*);


};

#endif // DATAREADER_H
