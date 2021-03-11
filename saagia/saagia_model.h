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

    void load_data();
    void set_new_data_content(QString);
    void save_data();
    void energy_form_1_selected();
    void energy_form_2_selected();
    void energy_form_3_selected();
    void energy_form_4_selected();

    void save_graph_as_image();

private:
    std::shared_ptr<Saagia_view> view_;
    std::shared_ptr<Data_reader> dataReader_;
    QString print_data_;

};

#endif // SAAGIA_MODEL_H
