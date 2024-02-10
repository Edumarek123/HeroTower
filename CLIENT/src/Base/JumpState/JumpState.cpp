#include "JumpState.hpp"
#include "../RunState/RunState.hpp"
#include "../FallingState/FallingState.hpp"

#include "../Hero/Hero.hpp"

JumpState::JumpState()
{
    _name = "JumpState";
}

void JumpState::enterState(Hero &player)
{
    std::cout << "Joined " << _name << std::endl;
    player._velocity.y -= 10;
    player._isGrounded = false;
}

void JumpState::exitState(Hero &player)
{
    std::cout << "Left " << _name << std::endl;
}

void JumpState::update(Hero &player)
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