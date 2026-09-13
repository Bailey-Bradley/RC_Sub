#pragma once

#include <Ethernet.h>

#define SPI_SCK_PIN 33
#define SPI_MISO_PIN 26
#define SPI_MOSI_PIN 25
#define SPI_CS_PIN 32

#define CONTROL_SERVER_PORT 50001

extern byte mac[];

extern IPAddress control_server_ip;

extern EthernetUDP udp;
extern EthernetServer tcp;

void ethernetSetup();
std::string getUDPMessage(EthernetUDP udp);
std::string getTCPMessage(EthernetServer tcp);