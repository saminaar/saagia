#include "saagia_controller.h"
#include "saagia_model.h"
#include <QDebug>

Saagia_controller::Saagia_controller(std::shared_ptr<Saagia_model> model,
                                     QObject *parent) :
    QObject{parent},
    model_{ model },
    start_time( "" ),
    end_time( "" ),
    start_hours_min("00:00:00"),
    end_hours_min("00:00:00"),
    energy_type( 0 )
{
}

void Saagia_controller::set_energy_type(int variable)
{
    energy_type = variable;
    model_->set_energy_type(variable);
}

void Saagia_controller::load_data()
{

    QString formatted_start_hours = start_hours_min.replace("\%3A", ":");
    QString formatted_end_hours = end_hours_min.replace("\%3A", ":");

    QString start_time_ready = start_time + "T" + formatted_start_hours + "Z";
    QString end_time_ready = end_time + "T" + formatted_end_hours + "Z";

    model_->load_data(start_time_ready, end_time_ready, energy_type);
   // qDebug() <<"START TIME: " << start_time << " END TIME: " << end_time ;
   // qDebug() << "START TIME: " << formatted_start_hours << " END TIME: " << end_hours_min;
   // model_->load_data(start_time, end_time, energy_type);
}

void Saagia_controller::set_the_selected_date(int type, QString date)
{

    switch(type){

        // Start date
        case 0 :
            start_time = date;
            break;

        // End date
        case 1 :
            end_time = date;
            break;

        default:
            start_time = "";
            end_time = "";
            break;

    }

}

void Saagia_controller::save_data(QString start_time, int data_type)
{
    /*
    model_->save_data(start_time, data_type);*/
}

/*
void Saagia_controller::energy_form_selected()
{

// Modulaarisuuden lisäämiseksi napeille tulisi tehdä
funktio, joka napin sisällön perusteella pistää asian
eteenpäin, eli EI silleen että jokaiselle napille
oma funktio

}
*/

void Saagia_controller::energy_form_1_selected()
{
    model_->energy_form_1_selected();
}

void Saagia_controller::energy_form_2_selected()
{
    model_->energy_form_2_selected();
}

void Saagia_controller::energy_form_3_selected()
{
    model_->energy_form_3_selected();
}

void Saagia_controller::energy_form_4_selected()
{
    model_->energy_form_4_selected();
}

void Saagia_controller::check_input()
{

    bool status = true;

    if((start_time == "") or (end_time == "")){
        status = false;
    }

    if (start_time > end_time){
        status = false;
    }

    if (start_time == end_time && start_hours_min > end_hours_min){
        status = false;
    }

    if(energy_type == 0){
        status = false;
    }

    model_->check_input(status);

}

bool Saagia_controller::check_place(QString text)
{
    text = text.toLower();
    bool checked = model_->check_placeinput(text);
    if (checked == true) qDebug() << "Location changed.";
}

void Saagia_controller::set_the_visible_date()
{

    model_->set_visible_date(start_time, end_time, start_hours_min, end_hours_min);

}

void Saagia_controller::set_the_selected_time(int type, QString time)
{

    switch(type){
        case 0 :
            start_hours_min = time;
            break;

        case 1 :
            end_hours_min = time;
            break;

        default:
            start_hours_min = "00:00:00";
            end_hours_min = "00:00:00";
            break;
    }

}

void Saagia_controller::save_chart_image()
{
    model_->save_graph_as_image();
}

void Saagia_controller::load_from_file(QString filename)
{


}

void Saagia_controller::save_to_file(QString filename)
{
    qDebug() << "Sending to model";
    qDebug() << filename;
    model_->save_data(filename);

}

// NOTE: no nullptr checks for model_ at all here!

