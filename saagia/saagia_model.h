#ifndef SAAGIA_MODEL_H
#define SAAGIA_MODEL_H

#include <memory>
#include <QDebug>

class Saagia_view;
class Data_calculations;
class Data_reader;
class Database_handler;
class Data_structures;

class Saagia_model
{

public:
    Saagia_model(std::shared_ptr<Saagia_view> view);

    void load_data(QString start_time, QString end_time, int variable, QString place = "Tampere");
    QString construct_url(QString start_time, QString end_time, int case_variable, QString place = "");
    void save_to_map(QString stime, int value);

    void set_chart_data();

    void set_energy_type(int type);

    void clear_database();
    void set_new_data_content(int value, QString date, int type);

    void energy_form_1_selected();
    void energy_form_2_selected();
    void energy_form_3_selected();
    void energy_form_4_selected();

    void check_input(bool status);

    void save_data(QString start_time, int data_type);
    void save_graph_as_image();
    void set_visible_date(QString stime, QString etime, QString shours, QString ehours);

private:
    std::shared_ptr<Saagia_view> view_;
    std::shared_ptr<Data_structures> data_structures_;
    std::shared_ptr<Data_reader> data_reader_;
    std::shared_ptr<Database_handler> database_handler_;
    QString print_data_;
    const QString header_ = "x-api-key:YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP";

    std::map<int, std::map<QString, int>> times_;

    int energy_type_;

};

#endif // SAAGIA_MODEL_H
