// IdleState.cpp
#include "IdleState.hpp"
#include "../RunState/RunState.hpp"
#include "../JumpState/JumpState.hpp"
#include "../AttackState/AttackState.hpp"

#include "../Hero/Hero.hpp"

IdleState::IdleState()
{
    _name = "IdleState";
}

void IdleState::enterState(Hero &player)
{
    std::cout << "Joined " << _name << std::endl;
}

void IdleState::exitState(Hero &player)
{
    std::cout << "Left " << _name << std::endl;
}

void IdleState::update(Hero &player)
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