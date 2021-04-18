#ifndef SAAGIA_MODEL_H
#define SAAGIA_MODEL_H

#include "saagia_view.h"
#include "data_structures.h"
#include "data_reader.h"
#include "database_handler.h"
#include "data_calculations.h"

#include <memory>
#include <QDebug>

class Saagia_view;
class Data_structures;
class Data_reader;
class Database_handler;
class Data_calculations;

class Saagia_model
{

public:
    Saagia_model(std::shared_ptr<Saagia_view> view);

    /**
     * @brief load_data: fetches desired dataset by creating an url and header and sending them to datareader
     * @param start_time: Starting time of the wanted dataset
     * @param end_time: Ending time of the desired dataset
     * @param variable: Variable used to recognize the desired dataset to be fetched
     * @param place: Location for weather data to be fetched
     */
    void load_data(QString start_time, QString end_time, int variable, QString place = "Pirkkala");


    /**
     * @brief set_chart_data: Sends wanted data to view to be shon in ui
     */
    void set_chart_data();

    /**
     * @brief set_energy_type: Sets the parameter energy_type_
     * @param type: Type of energy to be set
     */
    void set_energy_type(int type);

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
    void set_new_data_content(int value, Time date, int type);

    /**
     * @brief energy_form_1_selected
     */
    void energy_form_1_selected();
    void energy_form_2_selected();
    void energy_form_3_selected();
    void energy_form_4_selected();


    /**
     * @brief check_input
     * @param status
     */
    void check_input(bool status);

    /**
     * @brief save_data
     */
    void save_data();

    /**
     * @brief save_graph_as_image
     */
    void save_graph_as_image();

    /**
     * @brief set_visible_date
     * @param stime
     * @param etime
     * @param shours
     * @param ehours
     */
    void set_visible_date(QString stime, QString etime, QString shours, QString ehours);

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
     * @brief load_from_file
     * @param file
     */
    void load_from_file(QString file);

    /**
     * @brief average_temps: Fetches average temeprature, average minimun temeprature and average maximum temperature
     *          of desired month
     * @param month: Month from witch to fetch the data
     * @param year: Chosen year
     * @param place: Location of the temperature data
     */
    void average_temps(int month, int year, QString place = "");

    /**
     * @brief calc_percentage_of_energy_prod: Calculates the percentage of desired energy production
     *          type from total production
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
    QString construct_url(QString start_time, QString end_time, int case_variable, QString place = "Pirkkala");

    //Pointer to Saagia_view object for related opeartions
    std::shared_ptr<Saagia_view> view_;

    //Pointer to Data_structure object for related opeartions
    std::shared_ptr<Data_structures> data_structures_;

    //Pointer to Data_reader object for related opeartions
    std::shared_ptr<Data_reader> data_reader_;

    //Pointer to Database_handler object for related opeartions
    std::shared_ptr<Database_handler> database_handler_;

    //Pointer to Data_calculations object for related opeartions
    std::shared_ptr<Data_calculations> data_calculations_;


    QString print_data_;

    //Header used for Fingrid api with API-key
    const QString header_ = "x-api-key:YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP";


    int energy_type_;

    //Location for weather data. Is set to pirkkala by default
    QString place_ = "Pirkkala";

};

#endif // SAAGIA_MODEL_H
