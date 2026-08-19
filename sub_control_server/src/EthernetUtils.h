#pragma once

#include <Ethernet.h>

#define SPI_SCK_PIN 18
#define SPI_MISO_PIN 19
#define SPI_MOSI_PIN 47
#define SPI_CS_PIN 5

#define CONTROL_SERVER_PORT 50001

extern byte mac[];

extern IPAddress control_server_ip;

extern EthernetUDP udp;

void ethernetSetup();
std::string getUDPMessage(EthernetUDP udp);