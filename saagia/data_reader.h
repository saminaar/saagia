#ifndef DATA_READER_H
#define DATA_READER_H

#include "data_structures.h"
#include "data_calculations.h"

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

#include <QObject>
#include <QString>
#include <QUrl>

class QNetworkAccessManager;
class Data_structures;

const float NO_VALUE = 9999;

class Data_reader: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl currentUrl READ getCurrentUrl NOTIFY currentUrlChanged)
    Q_PROPERTY(int currentStatuscode READ getCurrentStatuscode NOTIFY currentStatuscodeChanged)
    Q_PROPERTY(QString currentContent READ getCurrentContent NOTIFY currentContentChanged)

public:
    explicit Data_reader(std::shared_ptr<Data_structures> data_structures, QObject* parent = nullptr);
    ~Data_reader();

    QUrl getCurrentUrl() const;
    int getCurrentStatuscode() const;
    QString getCurrentContent() const;

    // HTTP request can contain multiple custom headers but support just one in this case
    Q_INVOKABLE void requestUrl(const QString& url, const QString& header = "");

    void set_data_type(int data_type);





private Q_SLOTS:
    void requestCompleted(QNetworkReply* networkReply);
    void requestError(QNetworkReply::NetworkError errorCode);
    void sslErrors_appeared(QNetworkReply* reply);

signals:
    void currentUrlChanged();
    void currentStatuscodeChanged();
    void currentContentChanged();

private:


    void parseJson(QString content);
    void parseXML(QString content);
 //   Data_structures::time construct_time(QString time_as_string);


    std::shared_ptr<Data_structures> data_structures_;
    QNetworkAccessManager* network_;
    QUrl currentUrl_;
    int currentStatuscode_;
    QString currentContent_;

    QString header_;
    int data_type_;


};

#endif // DATA_READER_H
