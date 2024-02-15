#include "AttackState.hpp"
#include "../StatesList/StatesList.hpp"

#include "../IdleState/IdleState.hpp"

#include "../Hero/Hero.hpp"

AttackState::AttackState()
{
    _tag = (int)eAttac11State;
}

void AttackState::enterState(Hero &player)
{
}

void AttackState::exitState(Hero &player)
{
}

void AttackState::update(Hero &player, int &_ticks)
{
    if (_ticks > 60)
    {
        player._stateMachine.setState(new IdleState(), player);
    }
    _ticks++;
}