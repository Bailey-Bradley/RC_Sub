#include <Arduino.h>
#include <vector>
#include <string>
#include <sstream>

#include <Adafruit_ADS1X15.h>
#include <Adafruit_MCP23X17.h>

Adafruit_ADS1015 adc;
Adafruit_MCP23X17 dgpio;

void setup() {
  Serial.begin(115200);

  adc.begin();
  dgpio.begin_I2C();
}

void loop() {
}

/*


void setup()
{
  Serial.begin(115200);
}

void loop()
{
}
*/

// Thruster control: THRUST <right: -1, 1> <forward: -1, 1> <up: -1, 1> <look_right: -1, 1> <look_up: -1, 1>
// Camera control: CAMERA MODE <day, night>
// Camera control: CAMERA MODE TOGGLE
// Lights control: LIGHTS <off/on>
// Lights control: LIGHTS TOGGLE

// Data sources:
// IMU, pressure sensor, temp sensor, battery level sensor, battery draw sensor