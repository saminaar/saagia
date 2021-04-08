#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH
#include <map>
#include <QString>

enum energy_types {

    electricity = 1,
    nuclear = 2,
    hydro = 3,
    wind = 4

};

struct wind_data{

    //lampotila
    //pilvisyys
    // ....
};


class Datastructures
{



public:

    Datastructures();

    void append_to_datastructure(int type);
    void clear_datastructures();
    std::map<int, std::map<QString, int>> get_energy_structure();

private:

    std::map<int, std::map<QString, int>> data_1;

    //std::map<Päivämäärä, structi tuulen statseista>


};

#endif // DATASTRUCTURES_HH
