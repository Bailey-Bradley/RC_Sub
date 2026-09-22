#include "Connection.h"

#include <qlogging.h>

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

Connection::Connection(const char* ip, const char* port) {
    if (connect_out(ip, port)) {
        qDebug("Connected successfully");
    } else {
        qDebug("Failed to connect...");
    }
}

bool Connection::connect_out(const char* ip, const char* port) {
    struct addrinfo *result = NULL, *ptr = NULL, hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int addrinfo_res = getaddrinfo(ip, port, &hints, &result);

    if (addrinfo_res != 0) {
        qDebug("ERROR: getaddrinfo failed");
        return false;
    }

    ptr = result;

    connect_socket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

    if (connect_socket == INVALID_SOCKET) {
        qDebug("ERROR socket() failed");
        return false;
    }

    int connect_res = connect(connect_socket, ptr->ai_addr, (int)ptr->ai_addrlen);

    if (connect_res == SOCKET_ERROR) {
        qDebug("ERROR: connect() failed");
        return false;
    }

    freeaddrinfo(result);

    if (connect_socket == INVALID_SOCKET) {
        qDebug("ERROR: Can't connect to server");
        return false;
    }

    return true;
}

void Connection::send_data(const char* data, int len) {
    int res = send(connect_socket, data, len, 0);

    if (res == SOCKET_ERROR) {
        qDebug("ERROR: Couldn't send");
    }
}