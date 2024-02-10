#include "RunState.hpp"
#include "../JumpState/JumpState.hpp"

#include "../Hero/Hero.hpp"

RunState::RunState()
{
    _name = "RunState";
}

void RunState::enterState(Hero &player)
{
    std::cout << " Joined " << _name << std::endl;
}

void RunState::exitState(Hero &player)
{
    std::cout << "Left " << _name << std::endl;
}

void RunState::update(Hero &player)
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