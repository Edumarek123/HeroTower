#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

#include <enet/enet.h>

#define _SERVER_PORT 4545

class ServerSocket
{
public:
    ENetHost *_server;

    ENetAddress _address;
    ENetEvent _event;

    ServerSocket();
    ~ServerSocket();

    bool initialize();
    bool connect();
    void update();
    void broadcastPacket(const char *data);
};

#endif