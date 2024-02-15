#include "ServerSocket.hpp"

#include <string.h>
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
        int uid = (int)event.peer->address.host + (int)event.peer->address.port;

        switch (event.type)
        {
        case ENET_EVENT_TYPE_CONNECT:
            std::cout << "Novo client conectado: " << event.peer->address.host << ":" << event.peer->address.port << std::endl;
            connect_player(objects, uid);

            break;
        case ENET_EVENT_TYPE_RECEIVE:
            input_new_player_keys(objects, (char *)event.packet->data, uid);

            enet_packet_destroy(event.packet);

            break;
        case ENET_EVENT_TYPE_DISCONNECT:
            std::cout << event.peer->address.host << ":" << event.peer->address.port << " disconnected" << std::endl;

            disconnected_player(objects, uid);

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
    objects._players[objects.get_empty_index()]._uniqueID = id;
}

void disconnected_player(GameObjects &objects, int id)
{
    std::cout << "disconectado foi:" << objects._players[objects.get_index(id)]._uniqueID << " Era: " << id << std::endl;

    strcpy(objects._players[objects.get_index(id)]._name, "Entity");
    objects._players[objects.get_index(id)]._uniqueID = -1;
}

void input_new_player_keys(GameObjects &objects, char *packet, int id)
{
    if (objects.get_index(id) != -1)
    {
        char *name = (char *)malloc(strlen(packet) + 1);

        for (int i = 0; i < strlen(packet) + 1; i++)
        {
            name[i] = packet[i];
        }

        strcpy(objects._players[objects.get_index(id)]._name, name);

        free(name);
    }

    deserialize(packet, objects._keys[objects.get_index(id)]);
}