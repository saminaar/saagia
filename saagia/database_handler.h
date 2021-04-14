#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H
#include <memory>

#include <QJsonObject>
#include <QString>
#include <vector>
#include <string>

class Data_structures;

class Database_handler
{

public:

    Database_handler(std::shared_ptr<Data_structures> data_structures);

    bool load_data();
    bool save_data(QString start_time, int data_type) const;

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    std::vector<std::string> read_municipalities();

    bool save_to_file();

private:
    std::shared_ptr<Data_structures> data_structures_;

};

#endif // DATABASE_HANDLER_H
