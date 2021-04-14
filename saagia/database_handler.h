#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <QJsonObject>
#include <QString>

class Data_structures;

class Database_handler
{

public:

    Database_handler(std::shared_ptr<Data_structures> data_structures);

    bool load_data();
    bool save_data(QString start_time, int data_type) const;

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    std::shared_ptr<Data_structures> data_structures_;

};

#endif // DATABASE_HANDLER_H
