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

    /**
     * @brief Saagia_controller::set_the_selected_date: Sets the start time or end
     * time to match the selected date
     * @param type: data type
     * @param date: date to be set
     */
    Q_INVOKABLE void set_the_selected_date(int type, QString date);
    /**
     * @brief dataset_1_selected: changes the state of selection to the stated dataset
     */
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
    /**
     * @brief reset_input: resets the input of the settings
     */
    Q_INVOKABLE void reset_input();
    /**
     * @brief check_input: checks if the settings are right for the data fetch
     * @return boolean value of input correctness
     */
    Q_INVOKABLE bool check_input();
    /**
     * @brief check_place
     * @param qtext
     */
    Q_INVOKABLE void check_place(QString qtext);
    /**
     * @brief set_the_visible_date: sets the date shown in UI based on the data
     */
    Q_INVOKABLE void set_the_visible_date();
    /**
     * @brief set_the_selected_time: set the time to the UI based on the data
     * @param type: type of current data
     * @param time: time of the data
     */
    Q_INVOKABLE void set_the_selected_time(int type, QString time);
    Q_INVOKABLE void save_chart_image();
    Q_INVOKABLE void erase_chart_and_data();
    /**
     * @brief save_to_file: saves the data to file
     * @param filename: given filename
     */
    Q_INVOKABLE void save_to_file(QString filename);
    /**
     * @brief load_from_file: loads data from a given file
     * @param file: name of the file
     */
    Q_INVOKABLE void load_from_file(QString file);
    /**
     * @brief get_average_temp: calculates the average temperature of a given year and month
     * @param month: given month
     * @param year: given year
     */
    Q_INVOKABLE void get_average_temp(int month, int year);

private:

    // Pointer to Saagia_model object for related operations
    std::shared_ptr<Saagia_model> model_;

    QString start_time_;
    QString end_time_;

    QString start_hours_min_;
    QString end_hours_min_;

    int data_type_;

};

#endif // SAAGIA_CONTROLLER_H
