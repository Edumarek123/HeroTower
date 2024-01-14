#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <vector>
#include "../Entity/Entity.hpp"

class Projectile : public Entity
{
public:
    bool _isActive = true;
    bool _isStatic = true;
    std::vector<int> _hittedIDs;

    int _ticks = 0;
    int _maxTicks;
    float _damage;
    float _damageWindow;
    int _speed;

    Projectile(const Entity &hero);
    void update(std::vector<Rect4> blocks);
};

#endif