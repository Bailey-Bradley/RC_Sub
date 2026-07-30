#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <random>

class TimedClass : public QObject {
    Q_OBJECT

private:

    QTimer m_timer;

public:
    TimedClass() {
        m_timer.setInterval(500);
        connect(&m_timer, &QTimer::timeout, this, &TimedClass::trigger);
        m_timer.start();
    }

    void trigger() {
        qDebug("Caleld!");
    }
};

#include "main.moc"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("rov_gui", "Main");

    TimedClass tc;

    return QGuiApplication::exec();
}
