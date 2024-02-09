#ifndef GAMEOBJECTS_HPP
#define GAMEOBJECTS_HPP

#include "../Hero/Hero.hpp"
#include "../Projectile/Projectile.hpp"

#define MAX_PLAYERS 20

struct GameObjects
{
    // Hero _players[MAX_PLAYERS];
    Projectile *projectiles;
};

#endif