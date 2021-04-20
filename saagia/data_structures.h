/* File: data_structures.h
 *
 * Authors: Niilo Rannikko, Linnea Viitanen, Sami Naarminen, Mikko Tuovinen
 * Last changed: 18.4.2021
 * Course: Software Design, Spring 2021, mandatory group project
 *
 * Summary of this file:
 * This class houses containers to store weather and energy data and functions
 * used to store the data into those containers and access it later.
 * Also contains the implementations of Weather_data and Time structs and some
 * operators for those structs.
 *
 */

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include "data_reader.h"
#include <map>
#include <vector>
#include <QString>
#include <QDebug>

/**
 * @brief The weather_data struct: Struct to store all weather related data
 * of some time point
 */
struct weather_data{
    float temperature;
    float wind_speed;
    float cloudines;
    float max_temp;
    float min_temp;
};

/**
 * @brief The Time struct: Struct for a point of time
 */
struct Time {
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

// "<" operator for Time structs
inline bool operator<(Time t1, Time t2)
{
    if ( t1.year < t2.year ) { return true; }
    else if ( t1.month < t2.month ) { return true; }
    else if ( t1.day < t2.day ) { return true; }
    else if ( t1.hour < t2.hour ) { return true; }
    else if ( t1.minute < t2.minute ) { return true; }
    else { return false; }
}

// "==" operator for Time structs
inline bool operator==(Time t1, Time t2)
{
    if ( t1.year == t2.year && t1.month == t2.month && t1.day == t2.day &&
            t1.hour == t2.hour && t1.minute == t2.minute ) {
        return true;
    }
    else {
        return false;
    }
}

class Data_structures
{

public:

    Data_structures();

    /**
     * @brief append_energy_data: Function for storing energy data
     * @param start_time: Time point of data
     * @param data_type: Which type of energy
     * @param value: the value of data
     */
    void append_energy_data(QString start_time, int data_type, int value);

    /**
     * @brief append_weather_data: Function for storing weather data
     * @param time: Point of time
     * @param wd: The weather data of a time point
     */
    void append_weather_data(QString time, weather_data wd);

    /**
     * @brief test_print: Test function used in development to check what
     * is stored
     */
    void test_print();

    /**
     * @brief clear_data_structures: Erases all saved data
     */
    void clear_data_structures();

    /**
     * @brief get_municipalities:
     * @return
     */
    std::vector<std::string> get_municipalities();

    /**
     * @brief set_municipalities
     * @param new_m
     */
    void set_municipalities(std::vector<std::string> new_m);

    /**
     * @brief get_energy_structure: Returns all stored energy data
     * @return
     */
    std::map<int, std::map<QString, int> > get_energy_structure();

    /**
     * @brief get_weather_data: Returns all weather data
     * @return
     */
    std::map<QString, weather_data> get_weather_data();

    /**
     * @brief get_data_type: Returns a specific type of energy data
     * @param type: wanted type of energy
     * @return
     */
    std::map<QString, int> get_data_type(int type);

    /**
     * @brief calc_time_diff: Calculates hour difference between
     * two Time structures
     * @param t1: first Time structure
     * @param t2: second Time structure
     * @return
     */
    int calc_time_diff(Time t1, Time t2);

    /**
     * @brief get_days_of_months: returns vector with the amount
     * of days in each month
     * @return
     */
    std::vector<int> get_days_of_months();

private:

    /**
     * @brief hours_of_date: Function that calculates the amount
     * of hours a Time point has
     * @param t: Time point to be calculated
     * @return: Amount of hours as int
     */
    int hours_of_date(Time t);

    // Container for all energy data
    std::map<int, std::map<QString, int>> energy_data_;

    // Container for all weather data
    std::map<QString, weather_data> weather_data_;

    // Vector of municipalities
    std::vector<std::string> municipalities_;

    // Vector that has in order the amount of days
    // a corresponding month would have
    const std::vector<int> days_of_months_ = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

};

#endif // DATA_STRUCTURES_H
