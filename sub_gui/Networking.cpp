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
}