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


void Data_structures::append_weather_data(QString time, weather_data wd)
{
    std::map<QString, weather_data>::iterator iter = weather_data_.find(time);
    // If data exists already, its not re saved
    if ( iter != weather_data_.end() ) {

    }

    else{

        weather_data_[time] = wd;
    }

}

void Data_structures::test_print()
{
    qDebug() << "Test print for data structures";
    std::map<int, std::map<QString, int>>::iterator it;
    for ( it = energy_data_.begin(); it != energy_data_.end(); it++ )
    {
        /*
        qDebug() << it->first << " Key";
        qDebug() << it->second;
        */
    }
}

void Data_structures::clear_data_structures()
{
    energy_data_.clear();
    weather_data_.clear();

}

void Data_structures::set_municipalities(std::vector<std::string> new_m){
    this->municipalities_ = new_m;
}

std::vector<std::string> Data_structures::get_municipalities(){
    return this->municipalities_;
}

std::map<int, std::map<QString, int> > Data_structures::get_energy_structure()
{
    return energy_data_;
}

std::map<QString, int> Data_structures::get_data_type(int type)
{
    return energy_data_[type];
}

std::map<QString, weather_data> Data_structures::get_weather_data()
{
    return weather_data_;
}

int Data_structures::calc_time_diff(Time t1, Time t2)
{
    return hours_of_date(t2) - hours_of_date(t1);
}

std::vector<int> Data_structures::get_days_of_months()
{
    return days_of_months_;
}


int Data_structures::hours_of_date(Time t)
{
    int hours_of_year = ((t.year - 1900) * 365 * 24);
    int hours_of_month = 0;
    int i = 0;
    if ( t.month > 1 ) {
        while ( i < t.month - 1 ) {
            hours_of_month += days_of_months_.at(i) * 24;
            i++;
        }
    }
    int hours_of_days = 0;
    if ( t.day > 1 ) {
        hours_of_days = (t.day - 1) * 24;
    }

    int hours = hours_of_year + hours_of_month + hours_of_days + t.hour;
    return hours;
}
