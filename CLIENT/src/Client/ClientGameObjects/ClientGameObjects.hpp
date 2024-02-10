#ifndef CLIENTGAMEOBJECTS_HPP
#define CLIENTGAMEOBJECTS_HPP

#include "../HeroClient/HeroClient.hpp"
#include "../ProjectileClient/ProjectileClient.hpp"
#include "../../Base/GameObjects/GameObjects.hpp"

struct ClientGameObjects
{
    HeroClient _players[MAX_PLAYERS];
    ProjectileClient _projectiles[MAX_PLAYERS];

    ClientGameObjects();
    void update(const GameObjects objects);
};

#endif