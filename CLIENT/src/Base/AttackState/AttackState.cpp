// AttackState.cpp
#include "AttackState.hpp"

#include "../IdleState/IdleState.hpp"

#include "../Hero/Hero.hpp"

AttackState::AttackState()
{
    _name = "AttackState";
}

void AttackState::enterState(Hero &player)
{
    std::cout << "Joined " << _name << std::endl;
}

void AttackState::exitState(Hero &player)
{
    std::cout << "Left " << _name << std::endl;
}

void AttackState::update(Hero &player)
{
    _ticks++;

    if (_ticks > 60)
    {
        player._stateMachine.setState(new IdleState(), player);
    }
}