#include "saagia_view.h"
#include <QDebug>

Saagia_view::Saagia_view(QObject *parent) :
    QObject{ parent },
    print_data_{ "" },
    chart_data_{},
    active_date_{"<b>Current timeframe:</b> <i>No timeframe selected </i>"},
    title_of_shown_data_{"Currently displayed: "},
    location_{"Pirkkala"}
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

void Saagia_view::setVisibility(int type)
{
    emit setLineVisibility(type);
}

QString Saagia_view::getChartData() const
{
    return chart_data_;
}

void Saagia_view::setChartData(int value, QString date, int type)
{
    emit sendChartData(value, date, type);
}

void Saagia_view::setWeatherChartData(QString date, weather_data data)
{
    emit sendWeatherData(date, data.cloudines, data.max_temp, data.min_temp, data.temperature, data.wind_speed);
}



void Saagia_view::set_the_visible_date(const QString &stime)
{
    active_date_ = stime;
    emit dateChanged();
}

void Saagia_view::set_location(QString locationn)
{
    location_ = locationn;
    emit locationChanged(locationn);
}

QString Saagia_view::get_location()
{
    return location_;
}

void Saagia_view::set_the_type_data(const QString& energy_type)
{
    title_of_shown_data_ = energy_type;
    emit currentlyShownChanged();
}

QString Saagia_view::getTypeData() const
{
    return title_of_shown_data_;
}

QString Saagia_view::getActiveDate() const
{
    return active_date_;
}

void Saagia_view::clear_chart_data()
{
    emit clearChartData();
    emit clearWeatherChartData();
}

void Saagia_view::add_chart_line(int type)
{
    emit addChartLine(type);
}

void Saagia_view::add_weather_chart_line()
{
    emit addWeatherChartLine();
}
