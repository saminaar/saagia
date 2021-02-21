#include "saagia_view.h"

Saagia_view::Saagia_view(QObject *parent) :
    QObject{ parent },
    print_data_{ "The program will print out stuff here. . ." }
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
