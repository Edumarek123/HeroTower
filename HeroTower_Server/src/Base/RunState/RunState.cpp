// RunState.cpp
#include "RunState.hpp"
#include "../StateMachine/StateMachine.hpp"
#include "../JumpState/JumpState.hpp"
#include "../Hero/Hero.hpp"

RunState::RunState(StateMachine *stateMachine)
{
    setStateMachine(stateMachine);
    _name = "RunState";
}

void RunState::enterState()
{
    std::cout << _stateMachine->_hero->_name << " Joined " << _name << std::endl;
}

void RunState::exitState()
{
    std::cout << "Left " << _name << std::endl;
}

void RunState::update()
{
    if (_stateMachine->_hero->_keys._aIsPressed)
    {
        _stateMachine->_hero->_velocity.x -= 2;
        _stateMachine->_hero->_isFacingLeft = true;
    }

    if (_stateMachine->_hero->_keys._dIsPressed)
    {
        _stateMachine->_hero->_velocity.x += 2;
        _stateMachine->_hero->_isFacingLeft = false;
    }

    if ((!_stateMachine->_hero->_keys._dIsPressed && !_stateMachine->_hero->_keys._aIsPressed) || (_stateMachine->_hero->_keys._dIsPressed && _stateMachine->_hero->_keys._aIsPressed))
    {
        _stateMachine->setState(new IdleState(_stateMachine));
    }

    if (_stateMachine->_hero->_keys._wIsPressed)
    {
        _stateMachine->setState(new JumpState(_stateMachine));
    }
}