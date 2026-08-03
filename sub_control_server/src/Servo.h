#pragma once

#include <Adafruit_PWMServoDriver.h>

class Servo {
public:

  Adafruit_PWMServoDriver *driver;

  int channel;
  int tick_min;
  int tick_max;
  int angular_width;
  int zero_angle;

private:
  float angle_tick_ratio;
  int starting_angle;

public:
  Servo(Adafruit_PWMServoDriver *driver, int channel, int pulse_min_us, int pulse_max_us, int frequency, int angular_width, int zero_angle, int start_angle);

  void reset();

  void setAngle(float angle);

  float angleToTick(float angle);
};