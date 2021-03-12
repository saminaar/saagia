#ifndef SAAGIA_MODEL_H
#define SAAGIA_MODEL_H

#include <memory>
#include <QDebug>

class Saagia_view;
class Data_calculations;
class Database_handler;
class Data_reader;


class Saagia_model
{

public:
    Saagia_model(std::shared_ptr<Saagia_view> view);


    void load_data(QString web_address_1, QString start_time, QString end_time);
    void set_new_data_content(QString);
    void save_data();
    void energy_form_1_selected();
    void energy_form_2_selected();
    void energy_form_3_selected();
    void energy_form_4_selected();

    bool set_chart_data();

    void save_tomap(QString value, QString stime, QString etime);

    void save_graph_as_image();

private:
    std::shared_ptr<Saagia_view> view_;
    std::shared_ptr<Data_reader> dataReader_;
    QString print_data_;
    std::map<QString, QString> times;


};

#endif // SAAGIA_MODEL_H
