// FallingState.cpp
#include "FallingState.hpp"
#include "../Hero/Hero.hpp"

FallingState::FallingState()
{
    _name = "FallingState";
}

void FallingState::enterState(Hero &player)
{
    std::cout << "Joined " << _name << std::endl;
}

void FallingState::exitState(Hero &player)
{
    std::cout << "Left " << _name << std::endl;
    player._velocity.y = 0; // deletar
    player._isGrounded = true;
}

void FallingState::update(Hero &player)
{
    if (player._isGrounded)
    {
        player._stateMachine.setState(new IdleState(), player);
    }
}