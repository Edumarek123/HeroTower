#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <vector>
#include "../Entity/Entity.hpp"
#include "../GameParameters/GameParameters.hpp"

class Projectile : public Entity
{
public:
    bool _isActive = false;
    bool _isStatic = false;
    int _hittedIDs[MAX_PLAYERS];

    int _ticks = 0;
    int _maxTicks = 60;
    float _damage;
    float _damageWindow;
    int _speed = 10;

    Projectile();
    Projectile(const Entity &hero);
    void update(const Rect4 *blocks);
};

#endif