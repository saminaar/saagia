#include "saagia_model.h"
#include "saagia_view.h"
#include "datareader.h"

Saagia_model::Saagia_model(std::shared_ptr<Saagia_view> view) :
    view_{ view },
    dataReader_{ std::make_shared<Data_reader>( std::shared_ptr<Saagia_model>( this ) ) },
    print_data_{},
    times_{},
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

void Saagia_model::load_data(QString stime, QString etime, int variable)
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

    if ( variable == 0 ){
        // If energy type was not selected, do nothing
        return;
    }

    if ( stime == "" ){
        // If start time was not selected, do nothing
        return;
    }

    if ( etime == "" ){
        // If end time was not selected, do nothing
        return;
    }

    // Rakennetaan tässä www-osoite valmiiksi ja käytetään sitä haussa
    // Build the complete web address and use it for fetching data
    QString full_web_address = (web_address + start_time + "&" + end_time);

    QString header = "x-api-key:YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP";

    dataReader_->requestUrl(full_web_address, header);

    QString currently_showing = default_text + energy_info;

    view_->set_the_type_data(currently_showing);

    /*
    qDebug() << "Tietojen haku onnistui";

    print_data_ = "Tietojen haku onnistui";
    //set_chart_data();

    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
    }
    */
}

void Saagia_model::save_to_map(QString stime, QString etime, int value)
{
    qDebug() << "Function save_to_map called";
    times_[stime] = value;

}

void Saagia_model::set_chart_data()
{
    // Function for changing the displayed chart data

    view_->clear_chart_data();

    qDebug() << "Mapin pyöritys:";
    std::map<QString, int>::iterator it;

    for (it = times_.begin(); it != times_.end(); it++)
    {
        qDebug() << it->first + " Key";

        qDebug() << it->second;
        set_new_data_content(it->second, it->first, energy_type_);
    }

}

void Saagia_model::set_energy_type(int type)
{
    energy_type_ = type;
}

void Saagia_model::clear_database()
{

    times_.clear();

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

