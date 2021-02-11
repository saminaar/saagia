#ifndef DATAREADER_H
#define DATAREADER_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class DataReader: public QMainWindow
{
    Q_OBJECT
public:
    DataReader();
public slots:
    void readData();

private:
    QString myURL =
            "http://opendata.fmi.fi/wfs?service=WFS&version=2.0.0&request=describeStoredQueries"; //Page containig FMI API-info in xml

private slots:
    void finish(QNetworkReply*);


};

#endif // DATAREADER_H
