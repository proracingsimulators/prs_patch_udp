#include <iostream>
#include <string>
#include <cstring>
#include <winsock2.h>
#include "TelemetryData.hpp"

#define UDP_PORT 53520
#define SERVER_IP "127.0.0.1"
#define VERSION 2

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Winsock startup error." << std::endl;
        return 1;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket initialization error." << std::endl;
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddress.sin_port = htons(UDP_PORT);

    TelemetryData data;

    data.roll = 1.0;
    data.pitch = 2.0;
    data.heave = 3.0;
    data.yaw = 4.0;
    data.sway = 5.0;
    data.surge = 6.0;
    data.tractionLoss = 7.0;
    data.gear = 8;

    printf("Client started. Writing to server:\n");
    printf("Roll | Pitch | Heave | Yaw | Sway | Surge | Loss | Gear |\n");

    while (true) {
        #if VERSION == 1
        int bytesSent = sendto(clientSocket, (char*)&data, sizeof(data), 0, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
        #else
        char str[512];
        int size = sprintf(str, "%f-%f-%f-%f-%f-%f-%f-%d", 
            data.roll,
            data.pitch,
            data.heave,
            data.yaw,
            data.sway,
            data.surge,
            data.tractionLoss,
            data.gear
        );
        int bytesSent = sendto(clientSocket, str, size, 0, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
        #endif
        if (bytesSent == SOCKET_ERROR) {
            std::cerr << "Error sending data." << std::endl;
            return 1;
        }
        printf("%f | %f | %f | %f | %f | %f | %f | %d |\n",
            data.roll,
            data.pitch,
            data.heave,
            data.yaw,
            data.sway,
            data.surge,
            data.tractionLoss,
            data.gear
        );
        Sleep(50);
    }

    closesocket(clientSocket);

    WSACleanup();

    return 0;
}
