#pragma once

#include <Adafruit_PWMServoDriver.h>

class Thruster {

    Adafruit_PWMServoDriver *driver;
    int channel;
    int min_ticks;
    int tick_to_speed_ratio;

public:
    Thruster(Adafruit_PWMServoDriver *driver, int channel, int frequency, int min_pulse_us, int max_pulse_us);

    void setSpeed(float speed);
};