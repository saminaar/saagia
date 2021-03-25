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

    void load_data(QString start_time, QString end_time, int variable);
    void save_to_map(QString data_type, QString stime, QString etime,int value);

    void set_chart_data();

    void set_energy_type(int type);

    void clear_database();
    void set_new_data_content(int value, QString date, int type);

    void energy_form_1_selected();
    void energy_form_2_selected();
    void energy_form_3_selected();
    void energy_form_4_selected();

    void save_data();
    void save_graph_as_image();
    void set_visible_date(QString stime, QString etime, QString shours, QString ehours);

private:
    std::shared_ptr<Saagia_view> view_;
    std::shared_ptr<Data_reader> data_reader_;
    QString print_data_;
    std::map<QString, int> times_;
    std::map<QString, std::map<QString, int>> datastorage_;
    int energy_type_;

};

#endif // SAAGIA_MODEL_H
