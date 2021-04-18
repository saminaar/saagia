#include "data_calculations.h"


Data_calculations::Data_calculations(std::shared_ptr<Data_structures> data_structures) :
    data_structures_{ data_structures }
{

}

std::vector<float> Data_calculations::average_temp_of_month(int month, int year)
{

   std::vector<float> average_temps = {};
   std::map<Time, weather_data> data = data_structures_->get_weather_data();
   std::map<Time, weather_data>::iterator iter = data.begin();
   float sum_of_average_temps = 0;
   float sum_of_min_temps = 0;
   float sum_of_max_temps = 0;
   float i = 0;
   while (iter != data.end()) {
       if (iter->first.year == year && iter->first.month == month) {
           if (iter->second.temperature != 9999 && iter->second.min_temp != 9999
                   && iter->second.max_temp != 9999) {
               sum_of_average_temps += iter->second.temperature;
               sum_of_min_temps += iter->second.min_temp;
               sum_of_max_temps += iter->second.max_temp;
               i++;
           }

       }
       iter++;
   }

   float av_temp = sum_of_average_temps / i;
   average_temps.push_back(av_temp);
   float av_min_temp = sum_of_min_temps / i;
   average_temps.push_back(av_min_temp);
   float av_max_temp = sum_of_max_temps / i;
   average_temps.push_back(av_max_temp);

   return average_temps;

}
