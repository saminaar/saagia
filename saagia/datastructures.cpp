#include "datastructures.hh"

Datastructures::Datastructures()
{

}

void Datastructures::append_to_datastructure(QString start_time, Type type, int value)
{

    std::map<Type, std::map<QString, int>>::iterator itr = data_1.find(type);

    // Check if the energy type is already in the database
    if(itr != data_1.end()){

        // Energy-type was already in map, append values
        data_1[type][start_time] = value;

    }

    else{

        // Energy-type was not yet found in the map, add it
        std::map<QString, int> new_map;
        new_map[start_time] = value;

        data_1[type] = new_map;
    }

}

void Datastructures::clear_datastructures()
{
    data_1.clear();
    //data_2.clear();

}

std::map<Type, std::map<QString, int> > Datastructures::get_energy_structure()
{

    return data_1;

}



