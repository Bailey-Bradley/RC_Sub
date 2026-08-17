// MS5837 pressure and temperature test file
#include "MS5837.h"

void setup() {
  Serial.begin(115200);
  delay(100);
}

void loop() {
  MS5837 sensor;
  if (!sensor.init()) {
    Serial.println("Sensor initialization failed!");
    delay(1000);
    return;
  }

  sensor.setModel(MS5837::MS5837_02BA); // Set the model to MS5837-02BA

  sensor.read(); // Read the sensor data

  float pressure = sensor.pressure(MS5837::Pa); // Get pressure in Pascals
  float temperature = sensor.temperature(); // Get temperature in Celsius
  float depth = sensor.depth(); // Get depth in meters
  float altitude = sensor.altitude(); // Get altitude in meters

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.print(" Pa, Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Depth: ");
  Serial.print(depth);
  Serial.print(" m, ");
  Serial.print(depth * 3.28084); // Convert depth to feet

  delay(1000); // Wait for a second before the next reading
}
