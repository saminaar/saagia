#include "saagia_model.h"
#include "saagia_view.h"
#include "datareader.h"

Saagia_model::Saagia_model(std::shared_ptr<Saagia_view> view) :
    view_{ view },
    dataReader_{ std::make_shared<Data_reader>( std::shared_ptr<Saagia_model>( this ) ) }
{

}

void Saagia_model::load_data(QString web_address_1, QString start_time, QString end_time)
{
    // rakennetaan tässä www-osoite valmiiksi ja käytetään sitä haussa
    QString web_address = (web_address_1 + start_time + "&" + end_time);

    QString header = "x-api-key:YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP";

    dataReader_->requestUrl(web_address, header);

    qDebug() << "Tietojen haku onnistui";

    print_data_ = "Tietojen haku onnistui";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
    }
}

void Saagia_model::set_new_data_content(QString new_content)
{
    if (view_ != nullptr)
    {
        view_->setPrintData(new_content);
    }
}

void Saagia_model::save_data()
{
    qDebug() << "Tietojen tallennus onnistui";
    //view_->display_saved_data

    print_data_ = "Tietojen tallennus onnistui";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
    }
}

void Saagia_model::energy_form_1_selected()
{
    qDebug() << "Energiamuoto 1 valittu";
    //view_->display_energy_form_1

    print_data_ = "Energiamuoto 1 valittu";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
    }

}

void Saagia_model::energy_form_2_selected()
{
    qDebug() << "Energiamuoto 2 valittu";

    print_data_ = "Energiamuoto 2 valittu";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
    }

}

void Saagia_model::energy_form_3_selected()
{
    qDebug() << "Energiamuoto 3 valittu";

    print_data_ = "Energiamuoto 3 valittu";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
    }

}

void Saagia_model::energy_form_4_selected()
{
    qDebug() << "Energiamuoto 4 valittu";

    print_data_ = "Energiamuoto 4 valittu";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
    }

}

void Saagia_model::save_graph_as_image()
{
    qDebug() << "Correct function";

}

