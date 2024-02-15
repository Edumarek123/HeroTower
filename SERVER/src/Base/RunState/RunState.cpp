#include "RunState.hpp"
#include "../StatesList/StatesList.hpp"

#include "../JumpState/JumpState.hpp"

#include "../Hero/Hero.hpp"

RunState::RunState()
{
    _tag = (int)eRunState;
}

void RunState::enterState(Hero &player)
{
}

void RunState::exitState(Hero &player)
{
}

void RunState::update(Hero &player, int &_ticks)
{
    if (player._keys._aIsPressed)
    {
        player._velocity.x -= 2;
        player._isFacingLeft = true;
    }

    if (player._keys._dIsPressed)
    {
        player._velocity.x += 2;
        player._isFacingLeft = false;
    }

    if ((!player._keys._dIsPressed && !player._keys._aIsPressed) || (player._keys._dIsPressed && player._keys._aIsPressed))
    {
        player._stateMachine.setState(new IdleState(), player);
    }

    if (player._keys._wIsPressed)
    {
        player._stateMachine.setState(new JumpState(), player);
    }
}