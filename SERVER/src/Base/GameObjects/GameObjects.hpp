#ifndef GAMEOBJECTS_HPP
#define GAMEOBJECTS_HPP

#include "../Hero/Hero.hpp"
#include "../Projectile/Projectile.hpp"
#include "../GameParameters/GameParameters.hpp"
#include "../GameMap/GameMap.hpp"
#include "../PlayerKeys/PlayerKeys.hpp"

struct GameObjects
{
    PlayerKeys _keys[MAX_PLAYERS];
    Hero _players[MAX_PLAYERS];
    Projectile _projectiles[MAX_PLAYERS];
    GameMap _map;

    int get_empty_index();
    int get_index(int id);
};

#endif