#include "saagia_model.h"
#include "saagia_view.h"
#include "data_structures.h"
#include "data_reader.h"
#include "database_handler.h"
#include "data_calculations.h"

Saagia_model::Saagia_model(std::shared_ptr<Saagia_view> view) :
    view_{ view },
    data_structures_{ std::make_shared<Data_structures>() },
    data_reader_{ std::make_shared<Data_reader>( std::shared_ptr<Data_structures> ( data_structures_ ) ) },
    database_handler_{ std::make_shared<Database_handler>( std::shared_ptr<Data_structures> ( data_structures_ ) ) },
    data_calculations_{ std::make_shared<Data_calculations>( std::shared_ptr<Data_structures> ( data_structures_ ) ) },
    print_data_{},
    energy_type_{0}
{
}

/*

    Fingrid variable id:t

Suomen sähkön kulutus: tunneittain: 124, 3min välein: 193
o   Suomen sähköntuotanto:  74, päivit. tunneittain
o   Tulevan vuorokauden sähkönkulutusennuste: 166, päivitetään tunneittain
o   Tulevan vuorokauden sähköntuotanto ennuste: 242, päivit. tunneittain
o   Tuulienergian tuotantoennuste seur. 36h, 245 (päivitetään tunneittain)
o   Tuuli-, vesi- ja ydinvoiman osuudet kokonaistuotannosta
    -	vesivoiman tuotanto:  3min välein, 191
    -	tuulivoiman tuotanto:  3min välein, 181
    - 	ydinvoiman tuotanto:  3min välein, 188

*/

void Saagia_model::load_data(QString start_time, QString end_time, int variable, QString place)
{
    QString url = construct_url(start_time, end_time, variable, place);
    if (variable == 5 | variable == 6) {
        data_reader_->requestUrl(url, "");
    }

    else {
        data_reader_->requestUrl(url, header_);
    }

    set_chart_data();
}


/*
void Saagia_model::load_data(QString stime, QString etime, int variable, QString place)
{
    QString web_address = "";
    QString start_time = "";
    QString end_time = "";
    QString default_text = "Currently displayed: ";
    QString energy_info = "";

    switch(variable) {
        case 0 :
            break;

        case 1 :
            // Energy consumption in Finland (hourly)
            web_address = "https://api.fingrid.fi/v1/variable/124/events/json?";
            qDebug() << variable;
            qDebug() << "Energy consumption in Finland selected";
            energy_info = "Electricity consumption in Finland (MWh/h)";

            // Start time is spelled "start_time"
            start_time = "start_time=" + stime;
            qDebug() << start_time;

            // End time is spelled "end_time"
            end_time = "end_time=" + etime;
            qDebug() << end_time;

            break;

        case 2 :
            // Wind data from FMI
            web_address = "https://opendata.fmi.fi/wfs?"
                          "request=getFeature&version=2.0.0&storedquery_id=fmi::observations::weather::simple"
                          "&place=Pirkkala&timestep=30&parameters=t2m,ws_10min,n_man&";
            qDebug() << variable;
            qDebug() << "Wind data from FMI selected";
            energy_info = "Wind data from FMI";

            // Start time is spelled "starttime"
            start_time = "starttime=" + stime;
            qDebug() << start_time;

            // End time is spelled "endtime"
            end_time = "endtime=" + etime;
            qDebug() << end_time;

            break;

        case 3 :
            // Nuclear energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/188/events/json?";
            qDebug() << variable;
            qDebug() << "Nuclear energy selected";
            energy_info = "Nuclear energy production in Finland (MWh/h)";

            // Start time is spelled "start_time"
            start_time = "start_time=" + stime;
            qDebug() << start_time;

            // End time is spelled "end_time"
            end_time = "end_time=" + etime;
            qDebug() << end_time;

            break;

        case 4 :
            // Hydro energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/191/events/json?";
            qDebug() << variable;
            qDebug() << "Hydro energy selected";
            energy_info = "Hydro energy production in Finland (MWh/h)";

            // Start time is spelled "start_time"
            start_time = "start_time=" + stime;
            qDebug() << start_time;

            // End time is spelled "end_time"
            end_time = "end_time=" + etime;
            qDebug() << end_time;

            break;

        case 5 :
            // Optional

            break;

        default :
            energy_info = "";
            break;
    }


    // Rakennetaan tässä www-osoite valmiiksi ja käytetään sitä haussa
    // Build the complete web address and use it for fetching data
    QString full_web_address = (web_address + start_time + "&" + end_time);

    QString header = "x-api-key:YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP";
    QString fmi = " https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&storedquery_id=fmi::observations::weather::simple&place=Pirkkala&timestep=30&parameters=t2m,ws_10min,n_man";
    //data_reader_->requestUrl(fmi, header);

    data_reader_->requestUrl(full_web_address, header);

    QString currently_showing = default_text + energy_info;

    view_->set_the_type_data(currently_showing);


    qDebug() << "Tietojen haku onnistui";

    print_data_ = "Tietojen haku onnistui";
    //set_chart_data();

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
    }

}

*/

QString Saagia_model::construct_url(QString start_time, QString end_time, int case_variable, QString place)
{
    QString web_address = "";
    QString url = "";
    QString energy_info = "";
    QString formated_start_time  ;
    QString formated_end_time  ;

    switch(case_variable) {
        case 0 :
            break;
        //https://api.fingrid.fi/v1/variable/188/events/csv?start_time=2021-01-18T22:00:00Z&end_time=2021-01-19T04:00:00Z
        case 1 :
            // Energy consumption in Finland (hourly)
            web_address = "https://api.fingrid.fi/v1/variable/124/events/json?";
            url = web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            return url;
            break;

        case 2 :
            // Nuclear energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/188/events/json?";
            url =  web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            return url;
            break;

        case 3 :
            // Hydro energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/191/events/json?";
            url =  web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            return url;
            break;

        case 4 :
            // Optional
            break;

        case 5 :
            // Any old weather data (temperature, wind, cloudiness)
            web_address = "https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&storedquery_id=fmi::observations::weather::simple";
            url = web_address + "&place=" + place + "&starttime=" + start_time + "&endtime=" + end_time + "&parameters=t2m,ws_10min,n_man";
            return url;

            break;

        case 6:
            //Temperature or wind forecast
            web_address = "https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&storedquery_id=fmi::forecast::hirlam::surface::point::simple";
            url = web_address + "&place=" + place + "&starttime=" + start_time + "&endtime=" + end_time + "&parameters=Temperature,WindSpeedMS";
            return  url;
            break;

        default :
            energy_info = "";
            break;
    }
    return url;

}

void Saagia_model::set_chart_data()
{
    // Function for changing the displayed chart data
    view_->clear_chart_data(energy_type_);

    std::map<int, std::map<QString, int>>::iterator it;

    // Parseri tähän joka kattoo ettei oo liikaa tavaraa..
    if (energy_type_ != 1){


        int i = 0;
        for (auto energy_type : data_structures_->get_energy_structure() )
        {

            // Enter another map
            for (auto key_value : energy_type.second){


                if (i == 20){

                    set_new_data_content(key_value.second, key_value.first, energy_type_);
                    i = 0;
                }
                else{
                    i += 1;
                }


            }

        }

    }

    else{

        for (auto energy_type : data_structures_->get_energy_structure() )
        {
            for (auto key_value : energy_type.second){

                set_new_data_content(key_value.second, key_value.first, energy_type_);
            }

        }
    }

}

void Saagia_model::set_energy_type(int type)
{
    energy_type_ = type;
    data_reader_->set_data_type(type);
}

void Saagia_model::set_new_data_content(int value, QString date, int type)
{
    if (view_ != nullptr)
    {
        view_->setChartData(value, date, type);
    }
}

void Saagia_model::energy_form_1_selected()
{
    //view_->display_energy_form_1

    print_data_ = "Energiamuoto 1 valittu";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
        view_->setVisibility(1);
    }

}

void Saagia_model::energy_form_2_selected()
{
    print_data_ = "Energiamuoto 2 valittu";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
        view_->setVisibility(2);
    }

}

void Saagia_model::energy_form_3_selected()
{
    qDebug() << "Energiamuoto 3 valittu";

    print_data_ = "Energiamuoto 3 valittu";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
        view_->setVisibility(3);
    }

}

void Saagia_model::energy_form_4_selected()
{

    print_data_ = "Energiamuoto 4 valittu";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
        view_->setVisibility(4);
    }

}

void Saagia_model::check_input(bool status)
{

    view_->input_checked(status);

}

void Saagia_model::load_municipalities(){
    data_structures_->set_municipalities(database_handler_->read_municipalities());
}

bool Saagia_model::check_placeinput(QString text){
    if (data_structures_->get_municipalities().size() == 0) load_municipalities();
    std::string stext = text.toStdString();
    std::vector<std::string> places = data_structures_->get_municipalities();
    for (int i = 0; i < places.size(); ++i){
        if (places[i] == stext){ place_ = text; qDebug() << place_; return true;}
    }
    return false;
}

void Saagia_model::save_data(QString start_time, int data_type)
{

    database_handler_->save_data(start_time, data_type);

    /*
    //view_->display_saved_data

    print_data_ = "Tietojen tallennus onnistui";

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
        view_->setVisibility(energy_type_);
    }
    */
}

void Saagia_model::save_graph_as_image()
{
    qDebug() << "Save graph as image.. to be implemented";

}

void Saagia_model::set_visible_date(QString stime, QString etime, QString shours, QString ehours)
{

    QString start_date = stime.mid(0, stime.length()-14);
    QString year = start_date.mid(0,4);
    QString month = start_date.mid(5,2);
    QString day = start_date.mid(8, 2);

    QString end_date = etime.mid(0, etime.length()-14);
    QString eyear = end_date.mid(0,4);
    QString emonth = end_date.mid(5,2);
    QString eday = end_date.mid(8, 2);

    QString starting = "Timeframe: " + day + "." + month + "." + year + ", " + shours.replace("\%3A", ":") + " - " + eday + "." + emonth + "." + eyear + ", " + ehours.replace("\%3A", ":");

    if(view_ != nullptr )
    {
        view_->set_the_visible_date(starting);
    }

}

