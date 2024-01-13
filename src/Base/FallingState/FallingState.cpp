// FallingState.cpp
#include "FallingState.hpp"
#include "../Hero/Hero.hpp"

FallingState::FallingState(StateMachine *stateMachine)
{
    setStateMachine(stateMachine);
    _name = "FallingState";
}

void FallingState::enterState()
{
    std::cout << "Joined " << _name << std::endl;
}

void FallingState::exitState()
{
    std::cout << "Left " << _name << std::endl;
    _stateMachine->_hero->_velocity.y = 0; // deletar
    _stateMachine->_hero->_isGrounded = true;
}

void FallingState::update()
{
    if (_stateMachine->_hero->_position.y > 200)
    {
        _stateMachine->setState(new IdleState(_stateMachine));
    }
}