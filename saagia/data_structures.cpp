#include "data_structures.h"


Data_structures::Data_structures()
{
    energy_data_ = {};
    weather_data_ = {};

}

void Data_structures::append_energy_data(QString start_time, int data_type, int value)
{

    std::map<int, std::map<QString, int>>::iterator itr = energy_data_.find(data_type);

    // Check if the energy type is already in the database
    if(itr != energy_data_.end()){

        // Energy-type was already in map, append values
        energy_data_[data_type][start_time] = value;

    }

    else{

        // Energy-type was not yet found in the map, add it
        std::map<QString, int> new_map;
        new_map[start_time] = value;

        energy_data_[data_type] = new_map;
    }

}

void Data_structures::append_weather_data(QString time, weather_data data)
{
    qDebug() << "Pääsin structureen! " << time;
    std::map<QString, weather_data>::iterator iter = weather_data_.begin();
    while (iter != weather_data_.end()) {
        if (iter->first == time) {
            qDebug() << "Time already exists in datastructure";
            return;
        }
        iter++;
    }
    weather_data_[time] = data;
    qDebug() << "Tallennettu structureen: " << time << " : " << data.temperature << "...";

}

void Data_structures::test_print()
{
    qDebug() << "Test print for data structures";
    std::map<int, std::map<QString, int>>::iterator it;
    for (it = energy_data_.begin(); it != energy_data_.end(); it++)
    {
        qDebug() << it->first << " Key";
        qDebug() << it->second;

    }

}

void Data_structures::clear_data_structures()
{
    energy_data_.clear();
    //data_2.clear();

}

std::map<int, std::map<QString, int> > Data_structures::get_energy_structure()
{

    return energy_data_;

}

