#include "JumpState.hpp"
#include "../StatesList/StatesList.hpp"

#include "../RunState/RunState.hpp"
#include "../FallingState/FallingState.hpp"

#include "../Hero/Hero.hpp"

JumpState::JumpState()
{
    _tag = (int)eRunState;
}

void JumpState::enterState(Hero &player)
{
    player._velocity.y -= 10;
    player._isGrounded = false;
}

void JumpState::exitState(Hero &player)
{
}

void JumpState::update(Hero &player, int &_ticks)
{
    if (player._keys._aIsPressed)
    {
        player._accelerataion.x -= 1;
        player._isFacingLeft = true;
    }

    if (player._keys._dIsPressed)
    {
        player._accelerataion.x += 1;
        player._isFacingLeft = false;
    }

    if (player._velocity.y > 0)
    {
        player._stateMachine.setState(new FallingState(), player);
    }
}