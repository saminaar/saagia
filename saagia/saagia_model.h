#ifndef SAAGIA_MODEL_H
#define SAAGIA_MODEL_H

#include <memory>
#include <QObject>

class Saagia_view;
class data_calculations;
class database_handler;
class datareader;

class Saagia_model : public QObject
{
    Q_OBJECT
public:
    Saagia_model(std::shared_ptr<Saagia_view> view);



private:
    std::shared_ptr<Saagia_view> view_;

};

#endif // SAAGIA_MODEL_H
