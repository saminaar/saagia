/* File: saagia_controller.h
 *
 * Authors: Niilo Rannikko, Linnea Viitanen, Sami Naarminen, Mikko Tuovinen
 * Last changed: 18.4.2021
 * Course: Software Design, Spring 2021, mandatory group project
 *
 * Summary of this file:
 * This class is responsible for guiding commands from ui and user to the program. The program uses model-view-contorller model
 * and this is the controller. Functions in this class represent the different opeartions the user can
 * ask from ui as well as some small functions to set the parameters right.
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

    Q_INVOKABLE void set_energy_type(int variable);
    Q_INVOKABLE void load_data();
    Q_INVOKABLE void save_data(QString start_time, int data_type);
    Q_INVOKABLE void set_the_selected_date(int type, QString date);
    Q_INVOKABLE void energy_form_1_selected();
    Q_INVOKABLE void energy_form_2_selected();
    Q_INVOKABLE void energy_form_3_selected();
    Q_INVOKABLE void energy_form_4_selected();

    Q_INVOKABLE void reset_input();
    Q_INVOKABLE bool check_input();
    Q_INVOKABLE bool check_place(QString qtext);

    Q_INVOKABLE void set_the_visible_date();

    //Q_INVOKABLE void set_the_currently_shown_type();

    Q_INVOKABLE void set_the_selected_time(int type, QString time);

    Q_INVOKABLE void save_chart_image();

    Q_INVOKABLE void load_from_file(QString file);

    Q_INVOKABLE void save_to_file(QString filename);

    Q_INVOKABLE void fetch_forecast(int data_type);

    Q_INVOKABLE void get_average_temp(int month, int year);

private:
    std::shared_ptr<Saagia_model> model_;

    QString start_time;
    QString end_time;

    QString start_hours_min;
    QString end_hours_min;


    int energy_type;
};

#endif // SAAGIA_CONTROLLER_H
