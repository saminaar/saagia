#include "saagia_model.h"


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

void Saagia_model::load_data(QString start_time, QString end_time, int variable, QString place, QString month, QString year)
{
    QString url = construct_url(start_time, end_time, variable, place);
    if (variable == 9 | variable == 10) {
        data_reader_->requestUrl(url, "");
    }

    else {
        data_reader_->requestUrl(url, header_);
    }
    set_chart_data();
}

QString Saagia_model::construct_url(QString start_time, QString end_time, int case_variable, QString place)
{
    QString web_address = "";
    QString url = "";
    QString data_info = "";

    switch(case_variable) {
        case 0 :
            break;

        case 1 :
            // Energy consumption in Finland (hourly)
            web_address = "https://api.fingrid.fi/v1/variable/124/events/json?";
            url = web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            data_info = "Electricity consumption in Finland (MWh/h)";
            break;

        case 2 :
            // Energy production in Finland (hourly)
            web_address = "https://api.fingrid.fi/v1/variable/74/events/json?";
            url = web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            data_info = "Electricity production in Finland (MWh/h)";
            break;

        case 3 :
            // Nuclear energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/188/events/json?";
            url =  web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            data_info = "Nuclear energy production in Finland (MWh/h)";
            break;

        case 4 :
            // Hydro energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/191/events/json?";
            url =  web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            data_info = "Hydro energy production in Finland (MWh/h)";
            break;

        case 5 :
            // Wind energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/181/events/json?";
            url =  web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            data_info = "Wind energy production in Finland (MWh/h)";
            break;

        case 6 :
            // Electricity consumption forecast 24h
            web_address = "https://api.fingrid.fi/v1/variable/165/events/json?";
            url =  web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            data_info = "Energy consumption forecast for next 24 hours (MWh/h";
            break;

        case 7 :
            // Energy production forecast 24h
            web_address = "https://api.fingrid.fi/v1/variable/242/events/json?";
            url =  web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            data_info = "Energy production forecast for next 24 hours (MWh/h";
            break;

        case 8 :
            // Wind production forecast 36h
            web_address = "https://api.fingrid.fi/v1/variable/245/events/json?";
            url =  web_address + "start_time=" + start_time + "&" + "end_time=" + end_time;
            data_info = "Wind production forecast for next 36h (MWh/h)";
        break;

        case 9 :
            // Any old weather data (temperature, wind, cloudiness)
            web_address = "https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&storedquery_id=fmi::observations::weather::simple";
            url = web_address + "&place=" + place + "&starttime=" + start_time + "&endtime=" + end_time + "&parameters=t2m,ws_10min,n_man";
            data_info = "Weather data from past";
            break;

        case 10 :
            // Temperature and wind forecast
            web_address = "https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&storedquery_id=fmi::forecast::hirlam::surface::point::simple";
            url = web_address + "&place=" + place + "&starttime=" + start_time + "&endtime=" + end_time + "&parameters=Temperature,WindSpeedMS";
            data_info = "Weather forecast";
            break;

        case 11 :
            // Fetch data to calculate average minimum, maximum and average temperature of a month
            web_address = "https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&storedquery_id=fmi::observations::weather::daily::simple";
            url = web_address + "&place=" + place_ + "&starttime=" + start_time + "&endtime=" + end_time + "&parameters=tday,tmin,tmax";

            break;

    }
    QString default_text = "Currently displayed: ";
    QString info_text = default_text + data_info;
    view_->set_the_type_data(info_text);
    return url;

}

void Saagia_model::set_chart_data()
{
    // Function for changing the displayed chart data
    view_->clear_chart_data();

    std::map<int, std::map<QString, int>>::iterator it;

    for (auto energy_type : data_structures_->get_energy_structure() )
    {
         view_->add_chart_line(energy_type.first);

        // Enter another map
        for (auto key_value : energy_type.second){

             set_new_data_content(key_value.second, key_value.first, energy_type.first);

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

    //view_->input_checked(status);

}

void Saagia_model::load_municipalities()
{
    data_structures_->set_municipalities(database_handler_->read_municipalities());
}

void Saagia_model::load_from_file(QString file){
    file = file.remove(0,8);
    if (database_handler_->load_data(file) == "false") return;
    QString data1 = database_handler_->load_data(file);
    //energy_type_ = setti.split(" ")[0].toInt();
    energy_type_ = data1.split("\n")[0].toInt();
    data_reader_->set_data_type(data1.split("\n")[0].toInt());
    data1.remove(0,2);
    data_reader_->parseJson(data1);
    qDebug() << "success";
    set_chart_data();
}

bool Saagia_model::check_placeinput(QString text){
    if (data_structures_->get_municipalities().size() == 0) load_municipalities();
    std::string stext = text.toStdString();
    std::vector<std::string> places = data_structures_->get_municipalities();
    for (int i = 0; i < places.size(); ++i){
        if (places[i] == stext){
            place_ = text; qDebug() << place_;
            text[0] = text[0].toUpper();
            view_->set_location(text);
            return true;
        }
    }
    return false;
}

void Saagia_model::average_temps(int month, int year, QString place)
{
    QString month_str;
    if (month < 10) {
        month_str = "0" + QString::number(month);
    }
    else {
        month_str = QString::number(month);
    }
    QString starting_date = QString::number(year) + "-" + month_str + "-01T00:00:00Z";
    int number_of_days_in_month = data_structures_->get_days_of_months().at(month-1);

    QString ending_date = QString::number(year) + "-" + month_str + "-" +
            QString::number(number_of_days_in_month) + "T23:00:00Z";

    QString url = construct_url(starting_date, ending_date, 11, place);
    data_reader_->requestUrl(url, "");

    std::vector<float> temps = data_calculations_->average_temp_of_month(month, year);

    qDebug() << "av min temp: " << temps.at(1) << "av max temp: " << temps.at(2) << "av temp: " << temps.at(0);

}

void Saagia_model::save_data()
{

    database_handler_->save_data();
    // database_handler_->save_data(start_time, data_type);

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

    shours = shours.replace("\%3A", ":");
    shours = shours.mid(0, shours.length() - 3);

    ehours = ehours.replace("\%3A", ":");
    ehours = ehours.mid(0, ehours.length() - 3);


    QString starting = "<b>Current timeframe: </b>" + day + "." + month + "." + year + ", " + shours + " <b>-</b> " + eday + "." + emonth + "." + eyear + ", " + ehours;

    if(view_ != nullptr )
    {
        view_->set_the_visible_date(starting);
    }

}

