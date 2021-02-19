#ifndef SAAGIA_MODEL_H
#define SAAGIA_MODEL_H

#include <memory>
#include <QDebug>

class Saagia_view;
class Data_calculations;
class Database_handler;
class Datareader;

class Saagia_model
{

public:
    Saagia_model(std::shared_ptr<Saagia_view> view);

    void load_data();
    void save_data();
    void energy_form_1_selected();

private:
    std::shared_ptr<Saagia_view> view_;
    QString print_data_;

};

#endif // SAAGIA_MODEL_H
