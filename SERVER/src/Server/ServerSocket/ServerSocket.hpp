#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

#include <enet/enet.h>
#include <vector>
#include "../../Base/GameObjects/GameObjects.hpp"

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
    void update(GameObjects &objects);
    void broadcastPacket(const char *data, int dataLen);
};

void connect_player(GameObjects &objects, int id);
void input_new_player_keys(GameObjects &objects, char *packet);

#endif