#include "ServerSocket.hpp"

#include <string>
#include <iostream>
#include <cstring>
#include "../../../GPS.hpp"

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

void ServerSocket::update()
{
    int timeout = 5;
    while (enet_host_service(_server, &_event, timeout) > 0)
    {
        switch (_event.type)
        {
        case ENET_EVENT_TYPE_CONNECT:
            std::cout << "Novo client conectado: " << _event.peer->address.host << ":" << _event.peer->address.port << std::endl;
            break;
        case ENET_EVENT_TYPE_RECEIVE:
            std::cout << "A packet of length " << _event.packet->dataLength << " containing " << _event.packet->data << " was received from " << _event.peer->address.host << ":" << _event.peer->address.port << " on channel " << _event.channelID << std::endl;
            {
                GPS ggppss;
                ggppss.print();

                ggppss.load((const char *)_event.packet->data);
                ggppss.print();
            }
            break;
        case ENET_EVENT_TYPE_DISCONNECT:
            std::cout << _event.peer->address.host << ":" << _event.peer->address.port << " disconnected" << std::endl;
            break;
        case ENET_EVENT_TYPE_NONE:
            std::cout << "ok" << std::endl;
            break;
        }
    }
}

void ServerSocket::broadcastPacket(const char *data)
{

    ENetPacket *packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
    enet_host_broadcast(_server, 0, packet);
}