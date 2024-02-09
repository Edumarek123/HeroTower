#include "ServerSocket.hpp"

#include <string>
#include <iostream>
#include "../../Base/SDerialization/SDerialization.hpp"

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

void ServerSocket::update(GameObjects &objects)
{
    ENetEvent event;

    int timeout = 5;

    while (enet_host_service(_server, &event, timeout) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_CONNECT:
            std::cout << "Novo client conectado: " << event.peer->address.host << ":" << event.peer->address.port << std::endl;

            connect_player(objects, (int)event.peer->address.host);

            break;
        case ENET_EVENT_TYPE_RECEIVE:
            std::cout << "A packet of length " << event.packet->dataLength << " containing " << event.packet->data << " was received from " << event.peer->address.host << ":" << event.peer->address.port << " on channel " << event.channelID << std::endl;
            {
                PlayerKeys p;
                deserialize((char *)event.packet->data, p);
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

void connect_player(GameObjects &objects, int id)
{
    objects._players[objects.get_empty_index()]._name = std::to_string(id);
}