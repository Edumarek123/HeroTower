#ifndef HERO_HPP
#define HERO_HPP

#include <vector>
#include "../Entity/Entity.hpp"
#include "../PlayerKeys/PlayerKeys.hpp"
#include "../StateMachine/StateMachine.hpp"
#include "../IdleState/IdleState.hpp"
#include "../RunState/RunState.hpp"

class Hero : public Entity
{
public:
    std::vector<std::string> _itens;

    StateMachine _stateMachine;

    PlayerKeys _keys;

    Hero(float x, float y) : Entity(x, y)
    {
        _stateMachine.setState(new IdleState(&_stateMachine));
        _stateMachine.setHero(this);
    }

    void update(const std::vector<Rect4> &blocks, PlayerKeys newKeys);
};

#endif