#ifndef SAAGIA_MODEL_H
#define SAAGIA_MODEL_H

#include "saagia_view.h"
#include "data_structures.h"
#include "data_reader.h"
#include "database_handler.h"
#include "data_calculations.h"

#include <memory>
#include <QDebug>

class Saagia_view;
class Data_structures;
class Data_reader;
class Database_handler;
class Data_calculations;

class Saagia_model
{

public:
    Saagia_model(std::shared_ptr<Saagia_view> view);

    void load_data(QString start_time, QString end_time, int variable, QString place = "Pirkkala", QString month = "", QString year = "");

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

    // void save_data(QString start_time, int data_type);
    void save_data(QString filename);
    void save_graph_as_image();
    void set_visible_date(QString stime, QString etime, QString shours, QString ehours);
    void load_municipalities();
    bool check_placeinput(QString text);

    void average_temps(int month, int year, QString place = "");

private:
    QString construct_url(QString start_time, QString end_time, int case_variable, QString place = "Pirkkala");

    std::shared_ptr<Saagia_view> view_;
    std::shared_ptr<Data_structures> data_structures_;
    std::shared_ptr<Data_reader> data_reader_;
    std::shared_ptr<Database_handler> database_handler_;
    std::shared_ptr<Data_calculations> data_calculations_;
    QString print_data_;
    const QString header_ = "x-api-key:YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP";

    std::map<int, std::map<QString, int>> times_;

    int energy_type_;
    QString place_ = "Pirkkala";

};

#endif // SAAGIA_MODEL_H
