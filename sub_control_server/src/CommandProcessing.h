#include <Ethernet.h>

#include <vector>
#include <string>

std::string getUDPMessage(EthernetUDP udp);
std::vector<std::string> split(std::string command_string);
void processCommand(EthernetUDP udp);