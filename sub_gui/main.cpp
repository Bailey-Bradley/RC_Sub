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
        m_timer.start();
    }

    void setFunc(std::function<void()> func) {
        connect(&m_timer, &QTimer::timeout, this, func);
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

    QObject *widget = engine.rootObjects().first()->findChild<QObject*>("temp_widget");

    if (widget != nullptr) {
        qDebug("Found it!");
        tc.setFunc([&widget]() { widget->setProperty("temp", float(rand() % 100)); });
    } else {
        qDebug("Me no find");
    }

    return QGuiApplication::exec();
}
