#ifndef HERO_HPP
#define HERO_HPP

#include <vector>

#include "../Base/Entity/Entity.hpp"
#include "../Base/PlayerKeys/PlayerKeys.hpp"

class Hero : public Entity
{
public:
    std::string _name;
    std::vector<std::string> _itens;

    PlayerKeys _keys;

    Hero(float x, float y) : Entity(x, y) {}
    using Entity::update;
};

#endif