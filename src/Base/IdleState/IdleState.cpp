// IdleState.cpp
#include "IdleState.hpp"
#include "../StateMachine/StateMachine.hpp"

#include "../RunState/RunState.hpp"
#include "../JumpState/JumpState.hpp"
#include "../AttackState/AttackState.hpp"

#include "../Hero/Hero.hpp"

IdleState::IdleState(StateMachine *stateMachine)
{
    setStateMachine(stateMachine);
    _name = "IdleState";
}

void IdleState::enterState()
{
    std::cout << "Joined " << _name << std::endl;
}

void IdleState::exitState()
{
    std::cout << "Left " << _name << std::endl;
}

void IdleState::update()
{
    _stateMachine->_hero->applyFriction();

    if (_stateMachine->_hero->_keys._aIsPressed || _stateMachine->_hero->_keys._dIsPressed)
    {
        _stateMachine->setState(new RunState(_stateMachine));
    }

    if (_stateMachine->_hero->_keys._wIsPressed)
    {
        _stateMachine->setState(new JumpState(_stateMachine));
    }

    if (_stateMachine->_hero->_keys._n1IsPressed)
    {
        _stateMachine->setState(new AttackState(_stateMachine));
    }
}