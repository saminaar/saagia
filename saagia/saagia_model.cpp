#include "saagia_model.h"

Saagia_model::Saagia_model(std::shared_ptr<Saagia_view> view) :
    view_{ view },
    data_structures_{ std::make_shared<Data_structures>() },
    data_reader_{ std::make_shared<Data_reader>( std::shared_ptr<Data_structures> ( data_structures_ ) ) },
    database_handler_{ std::make_shared<Database_handler>( std::shared_ptr<Data_structures> ( data_structures_ ) ) },
    data_calculations_{ std::make_shared<Data_calculations>( std::shared_ptr<Data_structures> ( data_structures_ ) ) },
    print_data_{},
    data_type_{0},
    place_{"Pirkkala"}
{
}

void Saagia_model::load_data(QString start_time, QString end_time, int variable,
                             QString place)
{
    QString url = construct_url(start_time, end_time, variable, place);
    if ( variable == 9 || variable == 11 ) {
        data_reader_->requestUrl(url, "");
    }

    else {
        data_reader_->requestUrl(url, header_);
    }
}

QString Saagia_model::construct_url(QString start_time, QString end_time,
                                    int case_variable, QString place)
{
    QString web_address = "";
    QString url = "";
    QString data_info = "";

    switch(case_variable) {
        case 0 :
            break;

        case 1 :
            // Electricity consumption in Finland (hourly)
            web_address = "https://api.fingrid.fi/v1/variable/124/events/json?";
            url = web_address + "start_time=" + start_time + "&" +
                    "end_time=" + end_time;
            data_info = "Electricity consumption in Finland (MWh/h)";
            break;

        case 2 :
            // Electricity production in Finland (hourly)
            web_address = "https://api.fingrid.fi/v1/variable/74/events/json?";
            url = web_address + "start_time=" + start_time + "&" +
                    "end_time=" + end_time;
            data_info = "Electricity production in Finland (MWh/h)";
            break;

        case 3 :
            // Nuclear energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/188/events/json?";
            url =  web_address + "start_time=" + start_time + "&" +
                    "end_time=" + end_time;
            data_info = "Nuclear energy production in Finland (MWh/h)";
            break;

        case 4 :
            // Hydro energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/191/events/json?";
            url =  web_address + "start_time=" + start_time + "&" +
                    "end_time=" + end_time;
            data_info = "Hydro energy production in Finland (MWh/h)";
            break;

        case 5 :
            // Wind energy production (3 min interval)
            web_address = "https://api.fingrid.fi/v1/variable/181/events/json?";
            url =  web_address + "start_time=" + start_time + "&" +
                    "end_time=" + end_time;
            data_info = "Wind energy production in Finland (MWh/h)";
            break;

        case 6 :
            // Electricity consumption forecast 24h
            web_address = "https://api.fingrid.fi/v1/variable/165/events/json?";
            url =  web_address + "start_time=" + start_time + "&" +
                    "end_time=" + end_time;
            data_info = "Energy consumption forecast for next 24 hours (MWh/h)";
            break;

        case 7 :
            // Electricity production forecast 24h
            web_address = "https://api.fingrid.fi/v1/variable/242/events/json?";
            url =  web_address + "start_time=" + start_time + "&" +
                    "end_time=" + end_time;
            data_info = "Electricity production forecast for next 24 hours (MWh/h)";
            break;

        case 8 :
            // Wind energy production forecast max 36h
            web_address = "https://api.fingrid.fi/v1/variable/245/events/json?";
            url =  web_address + "start_time=" + start_time + "&" +
                    "end_time=" + end_time;
            data_info = "Wind energy production forecast for next 36h (MWh/h)";
            break;

        case 9 :
        // Fetch data to calculate average minimum, maximum and average
        // temperature of a month
            web_address = "https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&storedquery_id=fmi::observations::weather::simple";
            url = web_address + "&place=" + place + "&starttime=" + start_time +
                    "&endtime=" + end_time + "&parameters=t2m,ws_10min,n_man";
            data_info = "Weather data from past";
            break;

        case 10 :
            // Temperature and wind forecast
            web_address = "https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&storedquery_id=fmi::forecast::hirlam::surface::point::simple";
            url = web_address + "&place=" + place + "&starttime=" + start_time +
                    "&endtime=" + end_time + "&parameters=Temperature,WindSpeedMS";
            data_info = "Weather forecast";
            break;

        case 11 :

            // Any old weather data (temperature, wind, cloudiness)
            web_address = "https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&storedquery_id=fmi::observations::weather::simple";
            url = web_address + "&place=" + place + "&starttime=" + start_time +
                    "&endtime=" + end_time + "&parameters=t2m,ws_10min,n_man";
            data_info = "Weather data from past";
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

    for ( std::pair<int, std::map<QString, int>> energy_type :
         data_structures_->get_energy_structure() ) {
         view_->add_chart_line(energy_type.first);

        // Enter another map
        for ( auto key_value : energy_type.second ) {
            set_new_data_content(key_value.second, key_value.first,
                                 energy_type.first);
        }
    }

    // Weather data
    std::map<QString, weather_data> data = data_structures_->get_weather_data();

    if ( data.size() > 0 ){
        view_->add_weather_chart_line();

        for ( std::pair<QString, weather_data> weather_time : data ) {

            set_weather_data_content(weather_time.first, weather_time.second);
        }
    }
}

void Saagia_model::set_data_type(int type)
{
    data_type_ = type;
    data_reader_->set_data_type(type);
}

void Saagia_model::set_new_data_content(int value, QString date, int type)
{
    if ( view_ != nullptr ) {
        view_->setChartData(value, date, type);
    }
}

void Saagia_model::set_weather_data_content(QString date, weather_data data)
{
    if ( view_ != nullptr ) {
        view_->setWeatherChartData(date, data);
    }
}

void Saagia_model::dataset_1_selected()
{
    print_data_ = "Electricity consumption in Finland";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(1);
    }
}

void Saagia_model::dataset_2_selected()
{
    print_data_ = "Electricity production in Finland";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(2);
    }
}

void Saagia_model::dataset_3_selected()
{
    print_data_ = "Nuclear energy production";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(3);
    }
}

void Saagia_model::dataset_4_selected()
{
    print_data_ = "Hydro energy production";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(4);
    }
}

void Saagia_model::dataset_5_selected()
{
    print_data_ = "Wind energy production";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(5);
    }
}

void Saagia_model::dataset_6_selected()
{
    print_data_ = "Electricity consumption forecast";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(6);
    }
}

void Saagia_model::dataset_7_selected()
{
    print_data_ = "Electricity production forecast";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(7);
    }
}

void Saagia_model::dataset_8_selected()
{
    print_data_ = "Wind energy production forecast";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(8);
    }
}

void Saagia_model::dataset_9_selected()
{
    print_data_ = "Temperature forecast";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(9);
    }
}

void Saagia_model::dataset_10_selected()
{
    print_data_ = "Wind speed forecast";

    if ( view_ != nullptr ) {
        view_->setPrintData(print_data_);
        view_->setVisibility(10);
    }
}

void Saagia_model::load_municipalities()
{
    data_structures_->set_municipalities(database_handler_->read_municipalities());
}

void Saagia_model::load_from_file(QString file){
    file = file.remove(0,8);
    if ( database_handler_->load_data(file) == "false" ) return;
    QString data1 = database_handler_->load_data(file);
    //energy_type_ = setti.split(" ")[0].toInt();
    data_type_ = data1.split("\n")[0].toInt();
    data_reader_->set_data_type(data1.split("\n")[0].toInt());
    data1.remove(0,2);
    data_reader_->parseJson(data1);
    set_chart_data();
}

bool Saagia_model::check_placeinput(QString text){
    if ( data_structures_->get_municipalities().size() == 0 ) load_municipalities();
    std::string stext = text.toStdString();
    std::vector<std::string> places = data_structures_->get_municipalities();
    for ( std::vector<std::string>::size_type i = 0; i < places.size(); ++i ) {
        if ( places[i] == stext ) {
            place_ = text; qDebug() << place_;
            text[0] = text[0].toUpper();
            view_->set_location(text);
            return true;
        }
    }
    return false;
}

void Saagia_model::fetch_forecast(int data_type)
{
    // Creating starting and ending points for forecasts 24h apart
    QString start_date = clock_->currentDateTime().toString(Qt::ISODate);
    QString start_year = start_date.mid(0,4);
    QString start_month = start_date.mid(5,2);
    QString start_day = start_date.mid(8,2);
    QString start_hour = start_date.mid(11,2);

    QString end_date = clock_->currentDateTime().addDays(1).toString(Qt::ISODate);
    QString end_year = end_date.mid(0,4);
    QString end_month = end_date.mid(5,2);
    QString end_day = end_date.mid(8,2);
    QString end_hour = end_date.mid(11,2);

    QString starting_time = start_year + "-" + start_month + "-" + start_day +
            "T" + start_hour + ":00:00Z";
    QString ending_time = end_year+ "-" + end_month + "-" + end_day + "T" +
            end_hour + ":59:00Z";

    QString url;
    QString header;

    //One url fetches all weather forecast data
    if ( data_type == 9 || data_type == 10 ) {
        url = construct_url(starting_time, ending_time, 10);
        header = "";
    }
    else {
        url = construct_url(starting_time, ending_time, data_type);
        header = header_;
    }
    data_reader_->requestUrl(url, header);
}

void Saagia_model::average_temps(int month, int year, QString place)
{
    QString month_str;
    if ( month < 10 ) {
        month_str = "0" + QString::number(month);
    }
    else {
        month_str = QString::number(month);
    }
    QString starting_date = QString::number(year) + "-" +
            month_str + "-01T00:00:00Z";
    int number_of_days_in_month = data_structures_->get_days_of_months().at(month-1);

    QString ending_date = QString::number(year) + "-" + month_str + "-" +
            QString::number(number_of_days_in_month) + "T23:00:00Z";

    QString url = construct_url(starting_date, ending_date, 11, place);
    data_reader_->requestUrl(url, "");

    std::vector<float> temps = data_calculations_->average_temp_of_month(month, year);

    qDebug() << "av min temp: " << temps.at(1) << "av max temp: " << temps.at(2)
             << "av temp: " << temps.at(0);
}

void Saagia_model::calc_percentage_of_energy_prod(int energy_type)
{
    // Creating starting and ending points for forecasts 24h apart
    QString start_date = clock_->currentDateTime().addSecs(-360).toString(Qt::ISODate);
    QString start_year = start_date.mid(0,4);
    QString start_month = start_date.mid(5,2);
    QString start_day = start_date.mid(8,2);
    QString start_hour = start_date.mid(11,2);

    QString end_date = clock_->currentDateTime().toString(Qt::ISODate);
    QString end_year = end_date.mid(0,4);
    QString end_month = end_date.mid(5,2);
    QString end_day = end_date.mid(8,2);
    QString end_hour = end_date.mid(11,2);

    QString starting_time = start_year + "-" + start_month + "-" + start_day +
            "T" + start_hour + ":00:00Z";
    QString ending_time = end_year+ "-" + end_month + "-" + end_day + "T" +
            end_hour + ":59:00Z";

    qDebug() << "alku: " << starting_time << " loppu: " << ending_time;

    //Fetching total energy production data to datastructure
    QString total_prod_url = construct_url(starting_time, ending_time, 2);
    data_reader_->set_data_type(2);
    data_reader_->requestUrl(total_prod_url, header_);

    //Fetching given energy type's production data to datastructure
    QString energy_type_prod_url = construct_url(starting_time, ending_time,
                                                 energy_type);
    data_reader_->set_data_type(energy_type);
    data_reader_->requestUrl(energy_type_prod_url, header_);
}

void Saagia_model::save_data(QString filename)
{
    database_handler_->save_data(filename, data_reader_->parsedData(data_type_));
}

void Saagia_model::save_graph_as_image()
{
    set_chart_data();
}

void Saagia_model::erase_chart_and_data()
{
    data_structures_->clear_data_structures();
    set_chart_data();
}

void Saagia_model::set_visible_date(QString stime, QString etime,
                                    QString shours, QString ehours)
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

    QString starting = "<b>Current timeframe: </b>" + day + "." + month + "." +
            year + ", " + shours + " <b>-</b> " + eday + "." + emonth + "." +
            eyear + ", " + ehours;

    if ( stime == "" ) {
        starting = "<b>Current timeframe: </b> <i>Showing 24 hour forecast(s)";
    }

    if ( view_ != nullptr ) {
        view_->set_the_visible_date(starting);
    }
}
