#include "saagia_view.h"

Saagia_view::Saagia_view(QObject *parent) :
    QObject{ parent },
    print_data_{ "The program will print out stuff here. . ." },
    chart_data_{}
{
}

QString Saagia_view::getPrintData() const
{
    return print_data_;
}

void Saagia_view::setPrintData(const QString &newValue)
{
    print_data_ = newValue;
    emit printDataChanged();
}

QString Saagia_view::getChartData() const
{
    return chart_data_;
}

void Saagia_view::setChartData(QString stime, int value)
{
    print_data_ = (stime, value);
    emit printDataChanged();
}
