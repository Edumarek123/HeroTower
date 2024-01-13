#include "Hero.hpp"

void Hero::update(const std::vector<Rect4> &blocks, PlayerKeys newKeys)
{
    _keys = newKeys;
    this->Entity::update(blocks);

    _stateMachine.update();
}