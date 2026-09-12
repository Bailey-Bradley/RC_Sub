#include <SPI.h>
#include <Ethernet.h>
#include "EthernetUtils.h"

byte mac[] = {
  0xDE,0xAD,0xBE,0xEF,0xFE,0xED
};

IPAddress control_server_ip(192,168,10,50);

EthernetUDP udp;
EthernetServer tcp(CONTROL_SERVER_PORT);

void ethernetSetup()
{
  SPI.begin(SPI_SCK_PIN, SPI_MISO_PIN, SPI_MOSI_PIN, SPI_CS_PIN);

  Ethernet.init(SPI_CS_PIN);
  Ethernet.begin(mac, control_server_ip);
  
  udp.begin(CONTROL_SERVER_PORT);
}

std::string getUDPMessage(EthernetUDP udp) {
  std::string packet;

  if (udp.parsePacket()) {
    packet = udp.readString().c_str();
  }

  return packet;
}

std::string getTCPMessage(EthernetServer tcp) {
  std::string packet;

  EthernetClient client = tcp.available();

  if (tcp.) {
    packet = tcp.readString().c_str();
  }

  return packet;
}