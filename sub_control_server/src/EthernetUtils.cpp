#include <SPI.h>
#include <Ethernet.h>
#include "EthernetUtils.h"

byte mac[] = {
  0xDE,0xAD,0xBE,0xEF,0xFE,0xED
};

IPAddress control_server_ip(192,168,10,50);

EthernetUDP udp;

void ethernetSetup()
{
  SPI.begin(SPI_SCK_PIN, SPI_MISO_PIN, SPI_MOSI_PIN, SPI_CS_PIN);

  Ethernet.init(SPI_CS_PIN);
  Ethernet.begin(mac, control_server_ip);
  
  udp.begin(CONTROL_SERVER_PORT);
}

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