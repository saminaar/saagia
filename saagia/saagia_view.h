/* File: saagia_view.h
 *
 * Authors: Niilo Rannikko, Linnea Viitanen, Sami Naarminen, Mikko Tuovinen
 * Last changed: 18.4.2021
 * Course: Software Design, Spring 2021, mandatory group project
 *
 * Summary of this file:
 * This class is resposible for the things shown to the user. The functions
 * in this class are used to control the ui.
 *
 */

#ifndef SAAGIA_VIEW_H
#define SAAGIA_VIEW_H

#include <memory>
#include <QObject>
#include <QString>
#include "data_structures.h"
#include "data_reader.h"
#include "database_handler.h"
#include "data_calculations.h"

class Saagia_view : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString print_data READ getPrintData WRITE setPrintData NOTIFY printDataChanged)
    Q_PROPERTY(QString active_data READ getActiveDate WRITE set_the_visible_date NOTIFY dateChanged)
    Q_PROPERTY(QString current_text READ getTypeData WRITE set_the_type_data NOTIFY currentlyShownChanged)
    Q_PROPERTY(QString current_location READ get_location WRITE set_location NOTIFY locationChanged)
    //Q_PROPERTY(QString chart_data READ getChartData WRITE setChartData NOTIFY chartDataChanged)

public:

    explicit Saagia_view(QObject *parent = nullptr);

    QString getPrintData() const;

    void setPrintData(const QString& newValue);

    void setVisibility(int type);

    QString getChartData() const;

    void setChartData(int value, QString date, int type);

    void setWeatherChartData(QString date, weather_data data);

    void set_the_visible_date(const QString& stime);

    void set_the_type_data(const QString& energy_type);

    QString getTypeData() const;

    QString getActiveDate() const;

    void set_location(QString location);

    QString get_location();

    void clear_chart_data();

    void add_chart_line(int type);

    void add_weather_chart_line();

signals:

    void printDataChanged();
    void chartDataChanged();
    void dateChanged();
    void locationChanged(QString s);
    void currentlyShownChanged();

    void setLineVisibility(int type);

    void sendChartData(int value, QString date, int type);

    void clearChartData();
    void clearWeatherChartData();
    void addChartLine(int type);

    void sendWeatherData(QString date, float cloudines, float max_temp, float min_temp, float temperature, float wind_speed);
    void addWeatherChartLine();

private:

    // with the push MVC, the component that communicates the values to the QML
    // side must have the actual values (because the view has no information
    // about the model), so they are also stored here

    QString print_data_;
    QString chart_data_;
    QString active_date_;
    QString title_of_shown_data_;
    QString location_;

};

#endif // SAAGIA_VIEW_H
