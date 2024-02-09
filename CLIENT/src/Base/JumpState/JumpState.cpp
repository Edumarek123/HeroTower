// JumpState.cpp
#include "JumpState.hpp"
#include "../StateMachine/StateMachine.hpp"
#include "../RunState/RunState.hpp"
#include "../FallingState/FallingState.hpp"
#include "../Hero/Hero.hpp"

JumpState::JumpState(StateMachine *stateMachine)
{
    setStateMachine(stateMachine);
    _name = "JumpState";
}

void JumpState::enterState()
{
    std::cout << "Joined " << _name << std::endl;
    _stateMachine->_hero->_velocity.y -= 10;
    _stateMachine->_hero->_isGrounded = false;
}

void JumpState::exitState()
{
    std::cout << "Left " << _name << std::endl;
}

void JumpState::update()
{
    if (_stateMachine->_hero->_keys._aIsPressed)
    {
        _stateMachine->_hero->_accelerataion.x -= 1;
        _stateMachine->_hero->_isFacingLeft = true;
    }

    if (_stateMachine->_hero->_keys._dIsPressed)
    {
        _stateMachine->_hero->_accelerataion.x += 1;
        _stateMachine->_hero->_isFacingLeft = false;
    }

    if (_stateMachine->_hero->_velocity.y > 0)
    {
        _stateMachine->setState(new FallingState(_stateMachine));
    }
}