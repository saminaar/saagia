#ifndef DATA_READER_H
#define DATA_READER_H

#include <QNetworkReply>
#include <QObject>
#include <QString>
#include <QUrl>

class QNetworkAccessManager;
class Saagia_model;

class Data_reader: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl currentUrl READ getCurrentUrl NOTIFY currentUrlChanged)
    Q_PROPERTY(int currentStatuscode READ getCurrentStatuscode NOTIFY currentStatuscodeChanged)
    Q_PROPERTY(QString currentContent READ getCurrentContent NOTIFY currentContentChanged)

public:
    explicit Data_reader(std::shared_ptr<Saagia_model> model, QObject* parent = nullptr);
    ~Data_reader();

    QUrl getCurrentUrl() const;
    int getCurrentStatuscode() const;
    QString getCurrentContent() const;

    // HTTP request can contain multiple custom headers but support just one in this case
    Q_INVOKABLE void requestUrl(const QString& url, const QString& header = "");

    void parseJson(QString content);

private Q_SLOTS:
    void requestCompleted(QNetworkReply* networkReply);
    void requestError(QNetworkReply::NetworkError errorCode);

signals:
    void currentUrlChanged();
    void currentStatuscodeChanged();
    void currentContentChanged();

private:
    void parseXML(QString content);

    QNetworkAccessManager* network_;
    QUrl currentUrl_;
    int currentStatuscode_;
    QString currentContent_;
    std::shared_ptr<Saagia_model> model_;

};

#endif // DATA_READER_H
