#include <Ethernet.h>

#include <vector>
#include <string>
#include <sstream>

std::string getUDPMessage(EthernetUDP udp) {
  std::string packet;

  char packet_buffer[UDP_TX_PACKET_MAX_SIZE+1];

  if (udp.parsePacket()) {
    while (udp.available()) {
      int num_read = udp.read(packet_buffer, UDP_TX_PACKET_MAX_SIZE);
      packet_buffer[num_read] = '\0';
      packet.append(packet_buffer);
    }
  }

  return packet;
}

std::vector<std::string> split(std::string command_string) {
  std::istringstream stream(command_string);
  std::vector<std::string> arguments;

  std::string argument;
  while (stream >> argument) {
    arguments.push_back(argument);
  }

  return arguments;
}

void processCommand(EthernetUDP udp) {
  std::string command_string = getUDPMessage(udp);

  if (command_string.length() == 0) return;

  std::vector<std::string> arguments = split(command_string);
  std::string command_name = arguments[0];

  if (command_name == "THRUSTER") {
    Serial.printf("It was a THRUSTER command");
  } else if (command_name == "CAMERA") {
    Serial.printf("It was a CAMERA command");
  }
}