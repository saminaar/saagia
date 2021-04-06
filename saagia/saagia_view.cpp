#include "saagia_view.h"
#include <QDebug>

Saagia_view::Saagia_view(QObject *parent) :
    QObject{ parent },
    print_data_{ "The program will print out stuff here. . ." },
    chart_data_{},
    active_date_{"Timeframe: "},
    title_of_shown_data_{"Currently displayed: "}
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
    qDebug() << "HERE?";

    emit sendChartData(value, date, type);

}


void Saagia_view::set_the_visible_date(const QString &stime)
{
    active_date_ = stime;
    emit dateChanged();

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

void Saagia_view::clear_chart_data(int type)
{
    emit clearChartData(type);
}

void Saagia_view::input_checked(bool status)
{
    if(status){
        emit inputCheckOk();
    }
    else{
        emit inputCheckNotOk();
    }

}

