/* File: data_reader.h
 *
 * Authors: Niilo Rannikko, Linnea Viitanen, Sami Naarminen, Mikko Tuovinen
 * Last changed: 18.4.2021
 * Course: Software Design, Spring 2021, mandatory group project
 *
 * Summary of this file:
 * Class for executing HTTP request and for parsing the information gotten from those requests.
 * Houses functions for creating the requests and separate parsers for JSON data from Fingrid
 * and XML data from FMI.
 *
 */

#ifndef DATA_READER_H
#define DATA_READER_H

#include "data_structures.h"
#include "data_calculations.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
//#include <QStringList> tarvitaanko?
#include <QNetworkReply>
//#include <QVariant> tarvitaanko?
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

    /**
     * @brief getCurrentUrl
     * @return
     */
    QUrl getCurrentUrl() const;

    /**
     * @brief getCurrentStatuscode
     * @return
     */
    int getCurrentStatuscode() const;

    /**
     * @brief getCurrentContent
     * @return
     */
    QString getCurrentContent() const;



    /**
     * @brief requestUrl: Constructs and executes a request to external API
     * @param url: Url address for HTTP request
     * @param header: Header for HTTP request. Only one is needed this time
     */
    Q_INVOKABLE void requestUrl(const QString& url, const QString& header = "");

    /**
     * @brief set_data_type
     * @param data_type
     */
    void set_data_type(int data_type);

    QString parsedData(int energy_type);


    /**
     * @brief parseJson: Parser for JSON-style of data from Fingrid
     * @param content: JSON text to be parsed
     */
    void parseJson(QString content);




private Q_SLOTS:
    void requestCompleted(QNetworkReply* networkReply);
    void requestError(QNetworkReply::NetworkError errorCode);
    void sslErrors_appeared(QNetworkReply* reply);

signals:
    void currentUrlChanged();
    void currentStatuscodeChanged();
    void currentContentChanged();

private:


    /**
     * @brief parseXML: Parser for XML-style of data from FMI
     * @param content: XML text to be parsed
     */
    void parseXML(QString content);

    //Pointer to Data_structures object for related operations
    std::shared_ptr<Data_structures> data_structures_;

    //Pointer to QNetworkAccessManager for use with API requests
    QNetworkAccessManager* network_;

    //Url address to be used with requests
    QUrl currentUrl_;


    int currentStatuscode_;

    //Text gotten from requests
    QString currentContent_;

    //Save point for the header used in requests
    QString header_;

    //Number corresponding a data type
    int data_type_;


};

#endif // DATA_READER_H
