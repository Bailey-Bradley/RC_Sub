#pragma once

#include <string>

class ThrusterPacket {
public:
    ThrusterPacket(const std::string& command_str);
    static const std::string command_name;

    float thruster1_speed;
    float thruster2_speed;
    float thruster3_speed;
};