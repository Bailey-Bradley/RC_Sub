#include "LightSettingsPacket.h"
#include "CommandParsing.h"

#include <vector>
#include <string>

LightSettingsPacket::LightSettingsPacket(const std::string& command_str) {
    std::vector<std::string> args = split(command_str);

    light_level = LightLevel(std::stoi(args[1]));
}

const std::string LightSettingsPacket::command_name = "lights";