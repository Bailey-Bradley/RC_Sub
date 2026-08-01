#include <SPI.h>
#include <Ethernet.h>
#include "EthernetUtils.h"

byte mac[] = {
  0xDE,0xAD,0xBE,0xEF,0xFE,0xED
};

IPAddress control_server_ip(192,168,10,50);
IPAddress computer_ip(192,168,10,117);

EthernetUDP udp;

void ethernetSetup()
{
  SPI.begin(SPI_SCK_PIN, SPI_MISO_PIN, SPI_MOSI_PIN, SPI_CS_PIN);

  Ethernet.init(SPI_CS_PIN);
  Ethernet.begin(mac, control_server_ip);
  
  udp.begin(CONTROL_SERVER_PORT);
}