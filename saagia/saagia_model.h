/* File: saagia_model.h
 *
 * Authors: Niilo Rannikko, Linnea Viitanen, Sami Naarminen, Mikko Tuovinen
 * Last changed: 18.4.2021
 * Course: Software Design, Spring 2021, mandatory group project
 *
 * Summary of this file:
 * This class is the heart of the back end. Model executes all the commands
 * given to it by saagia_controller with the help of multiple other classes.
 * Model also sends the prosessed data to saagia_view to be showed
 * to the user in ui.
 *
 */

#ifndef SAAGIA_MODEL_H
#define SAAGIA_MODEL_H

#include "saagia_view.h"
#include "data_structures.h"
#include "data_reader.h"
#include "database_handler.h"
#include "data_calculations.h"

#include <memory>
#include <QDebug>
#include <QDateTime>

class Saagia_view;
class Data_structures;
class Data_reader;
class Database_handler;
class Data_calculations;

/* Datasets:
 * 1 = Electricity consumption in Finland
 * 2 = Electricity production in Finland
 * 3 = Nuclear energy production
 * 4 = Hydro energy production
 * 5 = Wind energy production
 * 6 = Electricity consumption forecast
 * 7 = Electricity production forecast
 * 8 = Wind energy production forecast
 * 9 = Temperature forecast
 * 10 = Wind speed forecast
 * 11 = Old temperature data
 * 12 = Old wind speed data
 * 13 = Old cloudiness data
 * 14 = Average temperature of a month
 * 15 = Average minimum temperature of month
 * 16 = Average maximum temperature of month
*/

class Saagia_model
{

public:

    Saagia_model(std::shared_ptr<Saagia_view> view);

    /**
     * @brief load_data: fetches desired dataset by creating an url and header
     * and sending them to datareader
     * @param start_time: Starting time of the wanted dataset
     * @param end_time: Ending time of the desired dataset
     * @param variable: Variable used to recognize the desired dataset
     * to be fetched
     * @param place: Location for weather data to be fetched
     */
    void load_data(QString start_time, QString end_time, int variable,
                   QString place = "Pirkkala");

    /**
     * @brief set_chart_data: Sends wanted data to view to be shon in ui
     */
    void set_chart_data();

    /**
     * @brief set_data_type: Sets the parameter data_type_
     * @param type: Type of data to be set
     */
    void set_data_type(int type);

    /**
     * @brief clear_database: Erases all saved data
     */
    void clear_database();

    /**
     * @brief set_new_data_content
     * @param value
     * @param date
     * @param type
     */
    void set_new_data_content(int value, QString date, int type);

    void set_weather_data_content(QString date, weather_data data);

    /**
     * @brief dataset_1_selected
     */
    void dataset_1_selected();
    void dataset_2_selected();
    void dataset_3_selected();
    void dataset_4_selected();
    void dataset_5_selected();
    void dataset_6_selected();
    void dataset_7_selected();
    void dataset_8_selected();
    void dataset_9_selected();
    void dataset_10_selected();

    // void save_data(QString start_time, int data_type);
    void save_data(QString filename);

    /**
     * @brief save_data
     */
    void save_data();

    /**
     * @brief save_graph_as_image
     */
    void save_graph_as_image();

    /**
     * @brief erase_chart_and_data
     */
    void erase_chart_and_data();

    /**
     * @brief set_visible_date
     * @param stime
     * @param etime
     * @param shours
     * @param ehours
     */
    void set_visible_date(QString stime, QString etime, QString shours,
                          QString ehours);

    /**
     * @brief load_municipalities
     */
    void load_municipalities();

    /**
     * @brief check_placeinput
     * @param text
     * @return
     */
    bool check_placeinput(QString text);

    /**
     * @brief fetch_forecast
     * @param data_type
     */
    void fetch_forecast(int data_type);

    /**
     * @brief load_from_file
     * @param file
     */
    void load_from_file(QString file);

    /**
     * @brief average_temps: Fetches average temperature, average minimun
     * temperature and average maximum temperature of the desired month
     * @param month: Month from which to fetch the data
     * @param year: Chosen year
     * @param place: Location of the temperature data
     */
    void average_temps(int month, int year, QString place = "");

    /**
     * @brief calc_percentage_of_energy_prod: Calculates the percentage of
     * desired energy production type from total production
     * @param energy_type: Chosen energy type ie. wind power
     */
    void calc_percentage_of_energy_prod(int energy_type);

private:

    /**
     * @brief construct_url: Construct url to be used for fetching desired data
     * @param start_time: Start time for the data set
     * @param end_time: End time for the data set
     * @param case_variable: Variable used to select wanted dataset
     * @param place: Location for weather data
     * @return: Finished url
     */
    QString construct_url(QString start_time, QString end_time,
                          int case_variable, QString place = "Pirkkala");

    // Pointer to Saagia_view object for related operations
    std::shared_ptr<Saagia_view> view_;

    // Pointer to Data_structure object for related operations
    std::shared_ptr<Data_structures> data_structures_;

    // Pointer to Data_reader object for related operations
    std::shared_ptr<Data_reader> data_reader_;

    // Pointer to Database_handler object for related operations
    std::shared_ptr<Database_handler> database_handler_;

    // Pointer to Data_calculations object for related operations
    std::shared_ptr<Data_calculations> data_calculations_;

    //
    QString print_data_;

    // Header used for Fingrid api with API key
    const QString header_ = "x-api-key:YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP";

    //
    int data_type_;

    // Location for weather data. Is set to Pirkkala by default
    QString place_;

    // QDateTime object used to get system clock
    QDateTime* clock_;

};

#endif // SAAGIA_MODEL_H
