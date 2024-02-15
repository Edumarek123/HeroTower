#include "ClientGameObjects.hpp"

ClientGameObjects::ClientGameObjects()
{
}

void ClientGameObjects::update(const GameObjects objects)
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        _players[i].copy(objects._players[i]);
        _projectiles[i].copy(objects._projectiles[i]);
    }
}