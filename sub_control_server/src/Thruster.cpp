#include "Thruster.h"

Thruster::Thruster(Adafruit_PWMServoDriver *driver, int channel, int frequency, int min_pulse_us, int max_pulse_us)
 : driver(driver), channel(channel) {
    float us_per_tick = 1.0 / frequency / 4096 * 1000000;

    min_ticks = min_pulse_us / us_per_tick;

    tick_to_speed_ratio = (max_pulse_us - min_pulse_us) / us_per_tick / 2;
}

void Thruster::setSpeed(float speed) {
    if (speed < -1 || 1 < speed) return;

    driver->setPWM(channel, 0, (speed + 1) * tick_to_speed_ratio + min_ticks);
}