#include "saagia_model.h"
#include "saagia_view.h"

Saagia_model::Saagia_model(std::shared_ptr<Saagia_view> view) :
    view_{ view }
{

}

void Saagia_model::load_data()
{
    // tähän kutsu datareaderille
    qDebug() << "Tietojen haku onnistui";
    //view_->display_loaded_data
}

void Saagia_model::save_data()
{
    qDebug() << "Tietojen tallennus onnistui";
    //view_->display_saved_data
}

void Saagia_model::energy_form_1_selected()
{
    qDebug() << "Energiamuoto 1 valittu";
    //view_->display_energy_form_1
}
