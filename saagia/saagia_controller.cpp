#include "saagia_controller.h"
#include "saagia_model.h"

Saagia_controller::Saagia_controller(std::shared_ptr<Saagia_model> model,
                                     QObject *parent) :
    QObject{parent},
    model_{ model }
{
}

void Saagia_controller::load_data(QString start_time, QString end_time, int variable)
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
    start_time = "start_time=2021-01-01T00:00:00Z";

    // tähän end_time
    end_time = "end_time=2021-01-01T23:00:00Z";

    model_->load_data(web_address, start_time, end_time);
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

