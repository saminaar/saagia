#include "saagia_controller.h"
#include "saagia_model.h"
#include "saagia_view.h"

#include <memory>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // setup the dependencies required by the push MCV model
    auto saagia_view{ std::make_shared<Saagia_view>() };
    auto saagia_model{ std::make_shared<Saagia_model>(saagia_view) };
    auto saagia_controller{ std::make_shared<Saagia_controller>(saagia_model) };

    // give the QML side access to the view and controller components
    auto context{ engine.rootContext() };
    context->setContextProperty("saagia_view", saagia_view.get());
    context->setContextProperty("saagia_controller", saagia_controller.get());

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
