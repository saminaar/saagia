/* File: saagia_controller.h
 *
 * Authors: Niilo Rannikko, Linnea Viitanen, Sami Naarminen, Mikko Tuovinen
 * Last changed: 18.4.2021
 * Course: Software Design, Spring 2021, mandatory group project
 *
 * Summary of this file:
 * This class is responsible for guiding commands from ui and user to the
 * program. The program uses model-view-controller model and this class is the
 * controller. Functions in this class represent the different operations the
 * user can ask from ui as well as some small functions to set the
 * parameters right.
 *
 */

#ifndef SAAGIA_CONTROLLER_H
#define SAAGIA_CONTROLLER_H

#include <memory>
#include <QObject>
#include <vector>

class Saagia_model;

class Saagia_controller : public QObject
{
    Q_OBJECT

public:

    explicit Saagia_controller(std::shared_ptr<Saagia_model> model,
                               QObject *parent = nullptr);

    /**
     * @brief Saagia_controller::set_data_type: sets the current data type to
     * match retrieved data type
     * @param variable: retrieved data type
     */
    Q_INVOKABLE void set_data_type(int variable);

    /**
     * @brief Saagia_controller::load_data: Formats the times for the data search
     */
    Q_INVOKABLE void load_data();

    //Q_INVOKABLE void save_data(QString start_time, int data_type);

    Q_INVOKABLE void set_the_selected_date(int type, QString date);
    Q_INVOKABLE void dataset_1_selected();
    Q_INVOKABLE void dataset_2_selected();
    Q_INVOKABLE void dataset_3_selected();
    Q_INVOKABLE void dataset_4_selected();
    Q_INVOKABLE void dataset_5_selected();
    Q_INVOKABLE void dataset_6_selected();
    Q_INVOKABLE void dataset_7_selected();
    Q_INVOKABLE void dataset_8_selected();
    Q_INVOKABLE void dataset_9_selected();
    Q_INVOKABLE void dataset_10_selected();
    Q_INVOKABLE void reset_input();
    Q_INVOKABLE bool check_input();
    Q_INVOKABLE void check_place(QString qtext);
    Q_INVOKABLE void set_the_visible_date();
    Q_INVOKABLE void set_the_selected_time(int type, QString time);
    Q_INVOKABLE void save_chart_image();
    Q_INVOKABLE void load_from_file(QString file);
    Q_INVOKABLE void save_to_file(QString filename);
    Q_INVOKABLE void fetch_forecast();
    Q_INVOKABLE void get_average_temp(int month, int year);

private:

    std::shared_ptr<Saagia_model> model_;

    QString start_time;
    QString end_time;

    QString start_hours_min;
    QString end_hours_min;

    int data_type;

};

#endif // SAAGIA_CONTROLLER_H
