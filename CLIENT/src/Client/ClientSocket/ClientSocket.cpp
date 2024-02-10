#include "ClientSocket.hpp"

#include <string>
#include <iostream>
#include <cstring>
#include "../../Base/SDerialization/SDerialization.hpp"
#include "../../Base/GameObjects/GameObjects.hpp"

ClientSocket::ClientSocket()
{
    initialize();

    enet_address_set_host(&_address, _SERVER_IP);
    _address.port = _SERVER_PORT;

    connect();
}

ClientSocket::~ClientSocket()
{
    enet_peer_disconnect(_peer, 0);
}

bool ClientSocket::initialize()
{
    if (enet_initialize() != 0)
    {
        std::cout << "Erro" << std::endl;
        return false;
    }
    atexit(enet_deinitialize);

    _client = enet_host_create(NULL, 1, 1, 0, 0);

    if (_client == NULL)
    {
        std::cout << "Erro client" << std::endl;
        return false;
    }

    return true;
}

bool ClientSocket::connect()
{
    _peer = enet_host_connect(_client, &_address, 1, 0);
    if (_peer == NULL)
    {
        std::cout << "Peer error" << std::endl;
        return false;
    }

    if (enet_host_service(_client, &_event, 5000) > 0 && _event.type == ENET_EVENT_TYPE_CONNECT)
    {
        std::cout << "Connected ok" << std::endl;
    }

    else
    {
        enet_peer_reset(_peer);
        std::cout << "Connected not ok" << std::endl;
        return false;
    }

    return true;
}

void ClientSocket::update(ClientGameObjects &objects)
{
    int timeout = 5;

    while (enet_host_service(_client, &_event, timeout) > 0)
    {
        switch (_event.type)
        {
        case ENET_EVENT_TYPE_RECEIVE:
            // std::cout << "A packet of length " << _event.packet->dataLength << " containing " << _event.packet->data << " was received from " << _event.peer->address.host << ":" << _event.peer->address.port << " on channel " << _event.channelID << std::endl;

            update_game_state((char *)_event.packet->data, objects);

            break;
        case ENET_EVENT_TYPE_CONNECT:
            std::cout << "Novo client conectado: " << _event.peer->address.host << ":" << _event.peer->address.port << std::endl;
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

void ClientSocket::sendPacket(const char *data, int dataLen)
{
    ENetPacket *packet = enet_packet_create(data, dataLen, ENET_PACKET_FLAG_RELIABLE);
    enet_peer_send(_peer, 0, packet);
}

void update_game_state(char *packet, ClientGameObjects &objects)
{
    GameObjects newObjects;
    deserialize(packet, newObjects);
    objects.update(newObjects);
}