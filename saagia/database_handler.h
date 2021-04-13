#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <QString>

class Data_structures;

class Database_handler
{

public:
    Database_handler(std::shared_ptr<Data_structures> data_structures);

    void save_data(QString start_time, int data_type_);

    void load_data();

private:
    std::shared_ptr<Data_structures> data_structures_;

};

#endif // DATABASE_HANDLER_H
