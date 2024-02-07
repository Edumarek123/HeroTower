#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

#include <enet/enet.h>
#include "../Base/Hero/Hero.hpp"
#include <vector>

#define _SERVER_PORT 4545

class ServerSocket
{
public:
    ENetHost *_server;
    ENetAddress _address;

    ServerSocket();
    ~ServerSocket();

    bool initialize();
    bool connect();
    void update(std::vector<Hero *> &players);
    void broadcastPacket(const char *data, int dataLen);
};

#endif