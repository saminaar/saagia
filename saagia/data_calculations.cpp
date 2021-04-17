#include "data_calculations.h"


Data_calculations::Data_calculations(std::shared_ptr<Data_structures> data_structures) :
    data_structures_{ data_structures }
{

}

float Data_calculations::average_temp_of_month(int month, int year)
{
   std::map<Time, weather_data> data = data_structures_->get_weather_data();
   std::map<Time, weather_data>::iterator iter = data.begin();
   float sum_of_temps = 0;
   float i = 0;
   while (iter != data.end()) {
       if (iter->first.year == year && iter->first.month == month) {
           sum_of_temps += iter->second.temperature;
           i++;
       }
       iter++;
   }
   return sum_of_temps/i;

}
