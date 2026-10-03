#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "FuncTimer.h"
#include "TemperatureWidget.h"

#define DATA_RATE 100

QQmlApplicationEngine *startQMLEngine(const QGuiApplication *app) {

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    QObject::connect(
        engine,
        &QQmlApplicationEngine::objectCreationFailed,
        app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine->loadFromModule("rov_gui", "Main");

    return engine;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine *engine = startQMLEngine(&app);
    FuncTimer data_timer(DATA_RATE);

    //QObject *widget = engine->rootObjects().first()->findChild<QObject*>("temp_widget");
    TemperatureWidget temp_widget = TemperatureWidget();
    engine->rootContext()->setContextProperty("TempSensor", &temp_widget);
    data_timer.setFunc([&temp_widget]() { temp_widget.setTemperature(rand() % 100); });

    /*
    if (widget != nullptr) {
        qDebug("Found it!");
        data_timer.setFunc([&widget]() { widget->setProperty("temp", float(rand() % 100)); });
    } else {
        qDebug("Me no find");
    }
    */

    return QGuiApplication::exec();
}
