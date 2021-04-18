/* File: data_structures.h
 *
 * Authors: Niilo Rannikko, Linnea Viitanen, Sami Naarminen, Mikko Tuovinen
 * Last changed: 18.4.2021
 * Course: Software Design, Spring 2021, mandatory group project
 *
 * Summary of this file:
 * This class houses containers to store weather and energy data and functions
 * used to store the data into those containers and access it later.
 * Also contains the implementations of Weather_data and Time structs and some operators
 * for those structs.
 *
 */

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include "data_reader.h"
#include <map>
#include <vector>
#include <QString>
#include <QDebug>

enum Type {

    electricity = 1,
    nuclear = 2,
    hydro = 3,
    wind = 4
};

enum month {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

struct weather_data{

    float temperature;
    float wind_speed;
    float cloudines;
    float max_temp;
    float min_temp;
};

struct Time {
    int year;
    int month;
    int day;
    int hour;
    int minute;
};
inline bool operator<(Time t1, Time t2)
{
    if (t1.year < t2.year) { return true; }
    else if (t1.month < t2.month) { return true; }
    else if (t1.day < t2.day) { return true; }
    else if (t1.hour < t2.hour) { return true; }
    else if (t1.minute < t2.minute) { return true; }
    else { return false; }
}

inline bool operator==(Time t1, Time t2)
{
    if (t1.year == t2.year && t1.month == t2.month && t1.day == t2.day && t1.hour == t2.hour && t1.minute == t2.minute) {
        return true;
    }
    else { return false; }
}

class Data_structures
{


public:

    Data_structures();

    void append_energy_data(Time start_time, int data_type, int value);
    void append_weather_data(Time time, weather_data);
    void test_print();
    void clear_data_structures();
    std::vector<std::string> get_municipalities();
    void set_municipalities(std::vector<std::string> new_m);
    std::map<int, std::map<Time, int> > get_energy_structure();
    std::map<Time, weather_data> get_weather_data();
    std::map<QString, int> get_data_type(int type);

    int calc_time_diff(Time t1, Time t2);
    std::vector<int> get_days_of_months();


private:

    int hours_of_date(Time t);
    std::map<int, std::map<Time, int>> energy_data_;
    std::map<Time, weather_data> weather_data_;
    std::vector<std::string> municipalities;
    const std::vector<int> days_of_months_ = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };



};

#endif // DATA_STRUCTURES_H
