#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Networking.h"
#include "Connection.h"
#include "FuncTimer.h"

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
    Networking::init();
    FuncTimer data_timer(DATA_RATE);

    Connection conn = Connection(ROV_SERVER_IP, ROV_SERVER_CONTROL_PORT);
    const char* packet = "Test Data";
    conn.send_data(packet, strlen(packet));

    QObject *widget = engine->rootObjects().first()->findChild<QObject*>("temp_widget");

    if (widget != nullptr) {
        qDebug("Found it!");
        data_timer.setFunc([&widget]() { widget->setProperty("temp", float(rand() % 100)); });
    } else {
        qDebug("Me no find");
    }

    return QGuiApplication::exec();
}
