#ifndef DATA_CALCULATIONS_H
#define DATA_CALCULATIONS_H
#include <memory>

#include <QString>

class Data_structures;

class Data_calculations
{
public:
    Data_calculations(std::shared_ptr<Data_structures> data_structures);

private:
    std::shared_ptr<Data_structures> data_structures_;

};

#endif // DATA_CALCULATIONS_H
