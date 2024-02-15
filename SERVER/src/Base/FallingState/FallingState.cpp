#include "FallingState.hpp"
#include "../StatesList/StatesList.hpp"

#include "../Hero/Hero.hpp"

FallingState::FallingState()
{
    _tag = (int)eFallingState;
}

void FallingState::enterState(Hero &player)
{
}

void FallingState::exitState(Hero &player)
{
    player._velocity.y = 0; // deletar
    player._isGrounded = true;
}

void FallingState::update(Hero &player, int &_ticks)
{
    if (player._isGrounded)
    {
        player._stateMachine.setState(new IdleState(), player);
    }
}