#include "saagia_controller.h"
#include "saagia_model.h"
#include <QDebug>

Saagia_controller::Saagia_controller(std::shared_ptr<Saagia_model> model,
                                     QObject *parent) :
    QObject{parent},
    model_{ model }
{
}

void Saagia_controller::load_data(QString starttime, QString endtime, int variable)
{
    QString web_address = "";

    switch(variable) {
        case 0 :
            // tähän haettavan datapaketin osoite 1
            web_address = "https://api.fingrid.fi/v1/variable/124/events/json?";
            break;
        case 1 :
            // tähän haettavan datapaketin osoite 2
            web_address = "https://opendata.fmi.fi/wfs?"
                          "request=getFeature&version=2.0.0&storedquery_id=fmi::observations::weather::simple"
                          "&place=Pirkkala&timestep=30&parameters=t2m,ws_10min,n_man";
            break;
        case 2 :
            // Optional
            break;
        case 3 :
            // Optional
            break;
        default :
            // Optional
            break;
    }

    // tähän start_time
    //starttime = "start_time=2021-01-01T00:00:00Z";
    starttime= "start_time=" + start_time;
    qDebug() << start_time;

    // tähän end_time
    //endtime = "end_time=2021-01-01T23:00:00Z";
    endtime = "end_time=" + end_time;
    qDebug() << end_time;

    model_->load_data(web_address, starttime, endtime);
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

void Saagia_controller::save_chart_image()
{
    model_->save_graph_as_image();
}
// NOTE: no nullptr checks for model_ at all here!

