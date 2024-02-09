#ifndef CLIENTSOCKET_HPP
#define CLIENTSOCKET_HPP

#include <enet/enet.h>
#include "../HeroClient/HeroClient.hpp"

#define _SERVER_IP "127.0.0.1"
#define _SERVER_PORT 4545

class ClientSocket
{
public:
    ENetHost *_client;

    ENetAddress _address;
    ENetEvent _event;
    ENetPeer *_peer;

    ClientSocket();
    ~ClientSocket();

    bool initialize();
    bool connect();
    void update(HeroClient &player);
    void sendPacket(const char *data, int dataLen);
};

#endif
