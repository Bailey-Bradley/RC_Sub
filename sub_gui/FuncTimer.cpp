#include "FuncTimer.h"

FuncTimer::FuncTimer(int data_rate) {
    m_timer.setInterval(data_rate);
    m_timer.start();
}

void FuncTimer::setFunc(std::function<void()> func) {
    connect(&m_timer, &QTimer::timeout, this, func);
}