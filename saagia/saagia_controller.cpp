#include "saagia_controller.h"
#include "saagia_model.h"

Saagia_controller::Saagia_controller(std::shared_ptr<Saagia_model> model,
                                     QObject *parent) :
    QObject{parent},
    model_{ model }
{
}

// NOTE: no nullptr checks for model_ at all here!

