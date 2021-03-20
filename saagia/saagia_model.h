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
    void save_to_map(QString stime, QString etime,int value);

    void set_chart_data();
    void set_new_data_content(QString stime, int value);

    void energy_form_1_selected();
    void energy_form_2_selected();
    void energy_form_3_selected();
    void energy_form_4_selected();

    void save_data();
    void save_graph_as_image();
    void set_visible_date(QString stime, QString etime);
    void set_currently_shown_text(int type);

private:
    std::shared_ptr<Saagia_view> view_;
    std::shared_ptr<Data_reader> dataReader_;
    QString print_data_;
    std::map<QString, int> times_;

};

#endif // SAAGIA_MODEL_H
