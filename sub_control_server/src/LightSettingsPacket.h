#pragma once

#include <string>

enum class LightLevel : std::uint8_t {
    OFF,
    LOW,
    HIGH
};

class LightSettingsPacket {
public:
    LightSettingsPacket(const std::string& command_str);
    static const std::string command_name;

    LightLevel light_level;
};