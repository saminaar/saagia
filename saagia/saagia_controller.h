#ifndef SAAGIA_CONTROLLER_H
#define SAAGIA_CONTROLLER_H

#include <memory>
#include <QObject>

class Saagia_model;

class Saagia_controller : public QObject
{
    Q_OBJECT

public:
    explicit Saagia_controller(std::shared_ptr<Saagia_model> model,
                               QObject *parent = nullptr);

    Q_INVOKABLE void set_energy_type(int variable);
    Q_INVOKABLE void load_data(QString start_time, QString end_time);
    Q_INVOKABLE void save_data();
    Q_INVOKABLE void change_startdate(QString date);
    Q_INVOKABLE void change_enddate(QString date);
    Q_INVOKABLE void energy_form_1_selected();
    Q_INVOKABLE void energy_form_2_selected();
    Q_INVOKABLE void energy_form_3_selected();
    Q_INVOKABLE void energy_form_4_selected();

    Q_INVOKABLE void set_the_visible_date();
    Q_INVOKABLE void set_the_currently_shown_type();

    Q_INVOKABLE void save_chart_image();

private:
    std::shared_ptr<Saagia_model> model_;
    QString start_time;
    QString end_time;
    int energy_type;
};

#endif // SAAGIA_CONTROLLER_H
