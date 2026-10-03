#include "Networking.h"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

#include <qlogging.h>

namespace Networking {
    int init() {
        WSADATA wsaData;
        int res = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (res != 0) {
            qDebug("ERROR: Winsock did NOT initialize");
            return 1;
        }

        return 0;
    }

    const char* ROV_SERVER_IP = "192.168.10.50";
    const char* ROV_SERVER_CONTROL_PORT = "50001";
    const char* ROV_SERBER_DATA_PORT = "50002";
}