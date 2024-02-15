#include "IdleState.hpp"
#include "../StatesList/StatesList.hpp"

#include "../RunState/RunState.hpp"
#include "../JumpState/JumpState.hpp"
#include "../AttackState/AttackState.hpp"

#include "../Hero/Hero.hpp"

IdleState::IdleState()
{
    _tag = (int)eIdleState;
}

void IdleState::enterState(Hero &player)
{
}

void IdleState::exitState(Hero &player)
{
}

void IdleState::update(Hero &player, int &_ticks)
{
    player.applyFriction();

    if (player._keys._aIsPressed || player._keys._dIsPressed)
    {
        player._stateMachine.setState(new RunState(), player);
    }

    if (player._keys._wIsPressed)
    {
        player._stateMachine.setState(new JumpState(), player);
    }

    if (player._keys._n1IsPressed)
    {
        player._stateMachine.setState(new AttackState(), player);
    }
}