#pragma once

#include <string>
#include <winsock2.h>

class Connection
{
    SOCKET connect_socket;

public:
    Connection(const char* ip, const char* port);

    bool connect_out(const char* ip, const char* port);
    void send_data(const char* data, int len);
};