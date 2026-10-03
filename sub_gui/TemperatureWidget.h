#pragma once

#include <QObject>

class TemperatureWidget : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float temp MEMBER temp NOTIFY tempChanged)

    float temp;

signals:
    void tempChanged();

public:
    TemperatureWidget();
    void setTemperature(float value);
};