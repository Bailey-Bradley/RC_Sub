#include "ThrusterPacket.h"
#include "CommandProcessing.h"

ThrusterPacket::ThrusterPacket(const std::string& command_str) {
    std::vector<std::string> args = split(command_str);

    thruster1_speed = std::stof(args[1]);
    thruster2_speed = std::stof(args[2]);
    thruster3_speed = std::stof(args[3]);
}

const std::string ThrusterPacket::command_name = "thruster";