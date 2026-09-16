#include <Arduino.h>

#include <string>

#include "CommandProcessor.h"
#include "CameraPacket.h"
#include "ThrusterPacket.h"
#include "EthernetUtils.h"

CommandProcessor<ThrusterPacket, CameraPacket> processor = CommandProcessor<ThrusterPacket, CameraPacket>();

void thrusterHandler(const ThrusterPacket& packet) {
  Serial.printf("THRUSTER:: Speed 1 = %f, Speed 2 = %f, Speed 3 = %f\n", packet.thruster1_speed, packet.thruster2_speed, packet.thruster3_speed);
}

void cameraHandler(const CameraPacket& packet) {
  Serial.printf("CAMERA:: Zoom level = %f, Night Vision = %d\n", packet.zoom_level, packet.night_vision);
}

void setup() {
  Serial.begin(115200);

  ethernetSetup();
  processor.addHandler<ThrusterPacket>(thrusterHandler);
  processor.addHandler<CameraPacket>(cameraHandler);
}

void loop() {
  std::string udp_message = getUDPMessage(udp);
  if (udp_message != "") {
    processor.processCommand(udp_message);
  }

  std::string tcp_message = getTCPMessage(tcp);
  if (tcp_message != "") {
    Serial.printf("MESSAGE RECEIVED: %s", tcp_message.c_str());
    //processor.processCommand(tcp_message);
  }

  delay(100);
}