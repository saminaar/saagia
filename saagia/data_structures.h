#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
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

struct weather_data{

    float temperature;    
    float wind_speed;
    QString cloudines = "NaN";
};


class Data_structures
{


public:

    Data_structures();

    void append_energy_data(QString start_time, int data_type, int value);
    void append_weather_data(QString time, weather_data);
    void test_print();
    void clear_data_structures();
    std::vector<std::string> get_municipalities();
    void set_municipalities(std::vector<std::string> new_m);
    std::map<int, std::map<QString, int>> get_energy_structure();

private:

    std::map<int, std::map<QString, int>> energy_data_;
    std::map<QString, weather_data> weather_data_;
    std::vector<std::string> municipalities;

    //std::map<Päivämäärä, structi tuulen statseista> data_2;


};

#endif // DATA_STRUCTURES_H
