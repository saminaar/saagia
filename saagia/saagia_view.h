#ifndef SAAGIA_VIEW_H
#define SAAGIA_VIEW_H

#include <memory>
#include <QObject>
#include <QString>

class Saagia_view : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString print_data READ getPrintData WRITE setPrintData NOTIFY printDataChanged)
    //Q_PROPERTY(QString chart_data READ getChartData WRITE setChartData NOTIFY chartDataChanged)
public:
    explicit Saagia_view(QObject *parent = nullptr);

    QString getPrintData() const;

    void setPrintData(const QString& newValue);

    QString getChartData() const;

    void setChartData(QString stime, int value);

signals:
    void printDataChanged();
    void chartDataChanged();


private:
    // with the push MVC, the component that communicates the values to the QML side,
    // must have the actual values (because the view has no information about the model),
    // so they are also stored here
    QString print_data_;
    QString chart_data_;

};

#endif // SAAGIA_VIEW_H
