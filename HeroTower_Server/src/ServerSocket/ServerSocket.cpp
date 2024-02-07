#include "ServerSocket.hpp"

#include <string>
#include <iostream>
#include "../PlayerKeys/PlayerKeys.hpp"
#include "../../../HeroTower/src/Base/SDerialization/SDerialization.hpp"

ServerSocket::ServerSocket()
{
    initialize();

    _address.host = ENET_HOST_ANY;
    _address.port = _SERVER_PORT;

    connect();
}

ServerSocket::~ServerSocket()
{
    enet_host_destroy(_server);
}

bool ServerSocket::initialize()
{
    if (enet_initialize() != 0)
    {
        std::cout << "Erro" << std::endl;
        return false;
    }
    atexit(enet_deinitialize);

    return true;
}

bool ServerSocket::connect()
{
    _server = enet_host_create(&_address, 32, 1, 0, 0);

    if (_server == NULL)
    {
        std::cout << "Erro server" << std::endl;
        return false;
    }

    return true;
}

void ServerSocket::update(std::vector<Hero *> &players)
{
    ENetEvent event;

    int timeout = 5;

    while (enet_host_service(_server, &event, timeout) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_CONNECT:
            std::cout << "Novo client conectado: " << event.peer->address.host << ":" << event.peer->address.port << std::endl;

            {
                players.emplace_back(new Hero(0.0f, 0.0f));
            }

            break;
        case ENET_EVENT_TYPE_RECEIVE:
            std::cout << "A packet of length " << event.packet->dataLength << " containing " << event.packet->data << " was received from " << event.peer->address.host << ":" << event.peer->address.port << " on channel " << event.channelID << std::endl;
            {
                // char *header = (char *)malloc((strlen((char *)event.packet->data) + 1) * sizeof(char));

                PlayerKeys p;
                deserialize((char *)event.packet->data, p);

                std::cout << "w: " << p._wIsPressed << " a: " << p._aIsPressed << " d: " << p._dIsPressed << std::endl;
            }

            break;
        case ENET_EVENT_TYPE_DISCONNECT:
            std::cout << event.peer->address.host << ":" << event.peer->address.port << " disconnected" << std::endl;
            break;
        case ENET_EVENT_TYPE_NONE:
            std::cout << "ok" << std::endl;
            break;
        }
    }
}

void ServerSocket::broadcastPacket(const char *data, int dataLen)
{
    ENetPacket *packet = enet_packet_create(data, dataLen, ENET_PACKET_FLAG_RELIABLE);
    enet_host_broadcast(_server, 0, packet);
}