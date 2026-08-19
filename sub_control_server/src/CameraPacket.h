#pragma once

#include <string>

class CameraPacket {
public:
    CameraPacket(const std::string& command_str);
    static const std::string command_name;

    float zoom_level;
    bool night_vision;
};
