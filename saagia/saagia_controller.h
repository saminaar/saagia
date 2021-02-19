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


private:
    std::shared_ptr<Saagia_model> model_;

};

#endif // SAAGIA_CONTROLLER_H
