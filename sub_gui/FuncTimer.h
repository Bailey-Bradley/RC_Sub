#pragma once

#include <QObject>
#include <QTimer>

class FuncTimer : public QObject {
    Q_OBJECT

private:

    QTimer m_timer;

public:
    FuncTimer(int data_rate);

    void setFunc(std::function<void()> func);
};