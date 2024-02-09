#ifndef GAMEOBJECTS_HPP
#define GAMEOBJECTS_HPP

#include "../Hero/Hero.hpp"
#include "../Projectile/Projectile.hpp"

#define MAX_PLAYERS 5

struct GameObjects
{
    Hero _players[MAX_PLAYERS];
    Projectile _projectiles[MAX_PLAYERS + MAX_PLAYERS];

    int get_empty_index();
};

#endif