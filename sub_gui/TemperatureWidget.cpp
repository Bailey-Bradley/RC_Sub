#include "TemperatureWidget.h"

TemperatureWidget::TemperatureWidget() : temp(0.0) {}

void TemperatureWidget::setTemperature(float value) {
    temp = value;
    tempChanged();
}