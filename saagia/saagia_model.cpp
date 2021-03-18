#include "saagia_model.h"
#include "saagia_view.h"
#include "datareader.h"

Saagia_model::Saagia_model(std::shared_ptr<Saagia_view> view) :
    view_{ view },
    dataReader_{ std::make_shared<Data_reader>( std::shared_ptr<Saagia_model>( this ) ) },
    print_data_{},
    times_{}
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

    switch(variable) {
        case 0 :
            break;

        case 1 :
            // Energy consumption in Finland (hourly)
            web_address = "https://api.fingrid.fi/v1/variable/124/events/json?";
            qDebug() << variable;
            qDebug() << "Energy consumption in Finland selected";

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

    qDebug() << "Tietojen haku onnistui";

    print_data_ = "Tietojen haku onnistui";


    if (view_ != nullptr)
    {
        view_->setPrintData(print_data_);
    }
}

void Saagia_model::set_new_data_content(int value, QString stime, QString etime)
{
    if (view_ != nullptr)
    {
        view_->setChartData(value, stime, etime);
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

void Saagia_model::save_to_map(int value, QString stime, QString etime){

    qDebug() << "Function called";
    set_new_data_content(value, stime, etime);

    times_[stime] = value;

    std::map<QString, int>::iterator it;

    /*
    qDebug() << "Mapin pyöritys:";
    for (it = times_.begin(); it != times_.end(); it++)
    {
        qDebug() << it->first + " Key";
        qDebug() << it->second;

    }
    */
}

void Saagia_model::save_graph_as_image()
{
    qDebug() << "Correct function";

}


bool Saagia_model::set_chart_data() {

    // Function for changing the displayed chart data
    return false;

    /*
    // Parses the raw data into usable formats

    // Both lists are for getting the min and max value
    // of each type (needed for the graph axises)
    var date_objects = [];
    var energy_values = [];

    // To make sure there aren't any values set yet
    energy_series.clear()

    // Messy parser.. does it's job
    for (var i in energy_data){

        var energy_value = energy_data[i]["value"];

        // Before parsing: "2021-01-01T01:00:00+0000"
        var parsed_time = energy_data[i]["start_time"].split('T');

        // Before parsing: "2021-01-01"
        var date = parsed_time[0].split('-')

        var year = date[0]
        var month = date[1]
        var day = date[2]

       // Before parsing: "01:00:00+0000"
        var time_hh_mm_ms = parsed_time[1].split('+')[0].split(':')

        var hours = time_hh_mm_ms[0]
        var mins = time_hh_mm_ms[1]
        var ms = time_hh_mm_ms[2]

        // Create a new datetime for the X-axis
        var new_date = new Date(year, month, day, hours, mins, ms)

        date_objects.push(new_date)
        energy_values.push(energy_value)

        var msecs = new_date.getTime();

        // Add the X,Y point to the chart
        energy_series.append(msecs, energy_value);

        // Set the min and max values for both axes.
        axisX.min = date_objects[0]
        axisX.max = date_objects[date_objects.length - 1]

        axisY.max = Math.max.apply(Math, energy_values)
        axisY.min =  Math.min.apply(Math, energy_values) - 500

    }
}
*/
}



