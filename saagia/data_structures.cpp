#include "data_structures.h"

Data_structures::Data_structures()
{

}

void Data_structures::append_to_data_structure(QString start_time, int data_type, int value)
{

    std::map<int, std::map<QString, int>>::iterator itr = data_1.find(data_type);

    // Check if the energy type is already in the database
    if(itr != data_1.end()){

        // Energy-type was already in map, append values
        data_1[data_type][start_time] = value;

    }

    else{

        // Energy-type was not yet found in the map, add it
        std::map<QString, int> new_map;
        new_map[start_time] = value;

        data_1[data_type] = new_map;
    }

}

void Data_structures::test_print()
{
    qDebug() << "Test print for data structures";
    std::map<int, std::map<QString, int>>::iterator it;
    for (it = data_1.begin(); it != data_1.end(); it++)
    {
        qDebug() << it->first << " Key";
        qDebug() << it->second;

    }

}

void Data_structures::clear_data_structures()
{
    data_1.clear();
    //data_2.clear();

}

std::map<int, std::map<QString, int> > Data_structures::get_energy_structure()
{

    return data_1;

}

