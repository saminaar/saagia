#include "saagia_controller.h"
#include "saagia_model.h"
#include <QDebug>

Saagia_controller::Saagia_controller(std::shared_ptr<Saagia_model> model,
                                     QObject *parent) :
    QObject{parent},
    model_{ model },
    start_time_( "" ),
    end_time_( "" ),
    start_hours_min_( "00:00:00" ),
    end_hours_min_( "00:00:00" ),
    data_type_( 0 )
{
}

void Saagia_controller::set_data_type(int variable)
{
    data_type_ = variable;
    model_->set_data_type(variable);
}

void Saagia_controller::load_data()
{
    if ( (data_type_ < 6) or (data_type_ == 11)) {
        get_average_temp(3, 2021);
        QString formatted_start_hours = start_hours_min_.replace("\%3A", ":");
        QString formatted_end_hours = end_hours_min_.replace("\%3A", ":");

        QString start_time_ready = start_time_ + "T" + formatted_start_hours + "Z";
        QString end_time_ready = end_time_ + "T" + formatted_end_hours + "Z";
        model_->load_data(start_time_ready, end_time_ready, data_type_);
    }

    if ( (data_type_ > 5) and (data_type_ < 11) ){
       model_->fetch_forecast(data_type_);
    }
}

void Saagia_controller::set_the_selected_date(int type, QString date)
{
    switch(type){
        // Start date
        case 0 :
            start_time_ = date;
            break;

        // End date
        case 1 :
            end_time_ = date;
            break;

        default:
            start_time_ = "";
            end_time_ = "";
            break;
    }
}

/*
Modulaarisuuden lisäämiseksi napeille tulisi tehdä
funktio, joka napin sisällön perusteella pistää asian
eteenpäin, eli EI silleen että jokaiselle napille
oma funktio
*/

void Saagia_controller::dataset_1_selected()
{
    model_->dataset_1_selected();
}

void Saagia_controller::dataset_2_selected()
{
    model_->dataset_2_selected();
}

void Saagia_controller::dataset_3_selected()
{
    model_->dataset_3_selected();
}

void Saagia_controller::dataset_4_selected()
{
    model_->dataset_4_selected();
}

void Saagia_controller::dataset_5_selected()
{
    model_->dataset_5_selected();
}

void Saagia_controller::dataset_6_selected()
{
    model_->dataset_6_selected();
}

void Saagia_controller::dataset_7_selected()
{
    model_->dataset_7_selected();
}

void Saagia_controller::dataset_8_selected()
{
    model_->dataset_8_selected();
}

void Saagia_controller::dataset_9_selected()
{
    model_->dataset_9_selected();
}

void Saagia_controller::dataset_10_selected()
{
    model_->dataset_10_selected();
}

void Saagia_controller::reset_input()
{
    data_type_ = 0;
    start_time_ = "";
    end_time_ = "";
    start_hours_min_ = "00:00:00";
    end_hours_min_ = "00:00:00";
}

bool Saagia_controller::check_input()
{
    if ( (data_type_ >= 5) and (data_type_ <= 11) ){
        return true;
    }

    if ( (start_time_ == "") or (end_time_ == "") ) {
        return false;
    }

    if ( start_time_ > end_time_ ) {
        return false;
    }

    if ( start_time_ == end_time_ && start_hours_min_ > end_hours_min_ ) {
        return false;
    }

    if ( data_type_ == 0 ) {
        return false;
    }

    return true;
}

void Saagia_controller::check_place(QString text)
{
    text = text.toLower();
    bool checked = model_->check_placeinput(text);
    if ( checked == true ) qDebug() << "Location changed.";
}

void Saagia_controller::set_the_visible_date()
{
    model_->set_visible_date(start_time_, end_time_, start_hours_min_,
                             end_hours_min_);
}

void Saagia_controller::set_the_selected_time(int type, QString time)
{
    switch(type){
        case 0 :
            start_hours_min_ = time;
            break;

        case 1 :
            end_hours_min_ = time;
            break;

        default:
            start_hours_min_ = "00:00:00";
            end_hours_min_ = "00:00:00";
            break;
    }
}

void Saagia_controller::save_chart_image()
{
    model_->save_graph_as_image();
}

void Saagia_controller::erase_chart_and_data()
{
    model_->erase_chart_and_data();
}

void Saagia_controller::save_to_file(QString filename)
{
    model_->save_data(filename);
}

void Saagia_controller::load_from_file(QString file)
{
    model_->load_from_file(file);
}

void Saagia_controller::get_average_temp(int month, int year)
{

}

// NOTE: no nullptr checks for model_ at all here!
