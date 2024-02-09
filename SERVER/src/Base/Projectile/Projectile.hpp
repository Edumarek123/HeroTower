#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <vector>
#include "../Entity/Entity.hpp"

class Projectile : public Entity
{
public:
    bool _isActive = true;
    bool _isStatic = false;
    std::vector<int> _hittedIDs;

    int _ticks = 0;
    int _maxTicks = 60;
    float _damage;
    float _damageWindow;
    int _speed = 10;

    Projectile();
    Projectile(const Entity &hero);
    void update(std::vector<Rect4> blocks);
};

#endif