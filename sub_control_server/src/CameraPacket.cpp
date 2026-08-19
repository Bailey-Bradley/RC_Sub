#include "CameraPacket.h"
#include "CommandProcessing.h"

#include <vector>
#include <string>

CameraPacket::CameraPacket(const std::string& command_str) {
    std::vector<std::string> args = split(command_str);

    zoom_level = std::stof(args[1]);
    night_vision = args[2] == "true";
}

const std::string CameraPacket::command_name = "camera";