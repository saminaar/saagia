#include "saagia_controller.h"
#include "saagia_model.h"

Saagia_controller::Saagia_controller(std::shared_ptr<Saagia_model> model,
                                     QObject *parent) :
    QObject{parent},
    model_{ model }
{
}

void Saagia_controller::load_data()
{
    model_->load_data();
}

void Saagia_controller::save_data()
{
    model_->save_data();
}

void Saagia_controller::energy_form_1_selected()
{
    model_->energy_form_1_selected();
}

// NOTE: no nullptr checks for model_ at all here!

