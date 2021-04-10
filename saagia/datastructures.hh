#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH
#include <map>
#include <vector>
#include <QString>

enum Type {

    electricity = 1,
    nuclear = 2,
    hydro = 3,
    wind = 4

};

struct wind_data{

    float temperature;
    // ...
};


class Datastructures
{


public:

    Datastructures();

    void append_to_datastructure(QString start_time, Type type, int value);
    void clear_datastructures();
    std::map<Type, std::map<QString, int>> get_energy_structure();

private:

    std::map<Type, std::map<QString, int>> data_1;

    //std::map<Päivämäärä, structi tuulen statseista> data_2;


};

#endif // DATASTRUCTURES_HH
