#ifndef DATA_CALCULATIONS_H
#define DATA_CALCULATIONS_H

#include "data_structures.h"

#include <memory>
#include <map>

#include <QString>

class Data_structures;

class Data_calculations
{

public:
    Data_calculations(std::shared_ptr<Data_structures> data_structures);

    float average_temp_of_month(int month, int year);
   // float percentage_of_all_energy_prod(int energy_type);





private:
    std::shared_ptr<Data_structures> data_structures_;

    //starting and ending dates for all months
   /*
    std::map<month, std::pair<QString, QString>> dates_of_months_ =
    {
       { JANUARY, {"01-01", "01-31"} },
       { FEBRUARY, {"02-01", "02-28"} },
       { MARCH, {"03-01", "03-31"} },
       { APRIL, {"04-01", "04-30"} },
       { MAY, {"05-01", "05-31"} },
       { JUNE, {"06-01", "06-30"} },
       { JULY, {"07-01", "07-31"} },
       { AUGUST, {"08-01", "08-31"} },
       { SEPTEMBER, {"09-01", "09-30"} },
       { OCTOBER, {"10-01", "10-31"} },
       { NOVEMBER, {"11-01", "11-30"} },
       { DECEMBER, {"12-01", "12-31"} }
    };
    */


};

#endif // DATA_CALCULATIONS_H
