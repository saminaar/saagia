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

    void append_energy_data(QString start_time, int data_type, int value);
    void append_weather_data(Time time, weather_data);
    void test_print();
    void clear_data_structures();
    std::vector<std::string> get_municipalities();
    void set_municipalities(std::vector<std::string> new_m);
    std::map<int, std::map<QString, int>> get_energy_structure();
    std::map<Time, weather_data> get_weather_data();
   // time construct_time_struct(QString time_in_str);

private:

    std::map<int, std::map<QString, int>> energy_data_;
    std::map<Time, weather_data> weather_data_;
    std::vector<std::string> municipalities;


};

#endif // DATA_STRUCTURES_H
