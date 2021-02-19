#ifndef SAAGIA_VIEW_H
#define SAAGIA_VIEW_H

#include <memory>
#include <QObject>
#include <QString>

class Saagia_view : public QObject
{
    Q_OBJECT

public:
    explicit Saagia_view(QObject *parent = nullptr);

signals:

private:
    // with the push MVC, the component that communicates the values to the QML side,
    // must have the actual values (because the view has no information about the model),
    // so they are also stored here

};

#endif // SAAGIA_VIEW_H
