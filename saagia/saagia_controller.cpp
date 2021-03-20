#include "saagia_controller.h"
#include "saagia_model.h"
#include <QDebug>

Saagia_controller::Saagia_controller(std::shared_ptr<Saagia_model> model,
                                     QObject *parent) :
    QObject{parent},
    model_{ model },
    start_time( "" ),
    end_time( "" ),
    energy_type( 0 )
{
}

void Saagia_controller::set_energy_type(int variable)
{
    energy_type = variable;
}

void Saagia_controller::load_data(QString starttime, QString endtime)
{
    starttime = start_time;

    endtime = end_time;

    model_->load_data(starttime, endtime, energy_type);
}

void Saagia_controller::change_startdate(QString date){
start_time = date.mid(1, date.length()-7) + "Z";
start_time.replace(":", "\%3A");
qDebug() << start_time;
}

void Saagia_controller::change_enddate(QString date){
end_time = date.mid(1, date.length()-7) + "Z";
end_time.replace(":", "\%3A");
qDebug() << end_time;
}

void Saagia_controller::save_data()
{
    model_->save_data();
}

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

void Saagia_controller::set_the_visible_date()
{
    model_->set_visible_date(start_time, end_time);
}

void Saagia_controller::set_the_currently_shown_type()
{
    model_->set_currently_shown_text(energy_type);
}

void Saagia_controller::save_chart_image()
{
    model_->save_graph_as_image();
}
// NOTE: no nullptr checks for model_ at all here!

