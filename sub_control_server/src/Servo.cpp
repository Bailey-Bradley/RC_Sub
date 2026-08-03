#include "Servo.h"
#include <Adafruit_PWMServoDriver.h>

Servo::Servo(Adafruit_PWMServoDriver *driver, int channel, int pulse_min_us, int pulse_max_us, int frequency, int angular_width, int zero_angle, int start_angle) :
driver(driver), channel(channel), angular_width(angular_width), zero_angle(zero_angle), starting_angle(start_angle) {
    float us_per_tick = 1.0 / float(frequency) / float(4096) * 1000000;

    tick_min = pulse_min_us / us_per_tick;
    tick_max = pulse_max_us / us_per_tick;

    angle_tick_ratio = float(tick_max - tick_min) / float(angular_width);
}

void Servo::reset() {
    setAngle(starting_angle);
}

void Servo::setAngle(float angle) {
    int ticks = angleToTick(angle);

    if (tick_min <= ticks && ticks <= tick_max) {
        driver->setPWM(channel, 0, ticks);
    }
}

float Servo::angleToTick(float angle) {
    return (angle + zero_angle) * angle_tick_ratio + tick_min;
}