#ifndef DATA_READER_H
#define DATA_READER_H

#include <QNetworkReply>
#include <QObject>
#include <QString>
#include <QUrl>

class QNetworkAccessManager;
class Data_structures;

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

    void parseJson(QString content);

private Q_SLOTS:
    void requestCompleted(QNetworkReply* networkReply);
    void requestError(QNetworkReply::NetworkError errorCode);

signals:
    void currentUrlChanged();
    void currentStatuscodeChanged();
    void currentContentChanged();

private:
    std::shared_ptr<Data_structures> data_structures_;
    void parseXML(QString content);

    QNetworkAccessManager* network_;
    QUrl currentUrl_;
    int currentStatuscode_;
    QString currentContent_;

    QString header_;
    int data_type_;
    const float NO_VALUE = 99999;

};

#endif // DATA_READER_H
