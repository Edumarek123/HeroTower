// AttackState.cpp
#include "AttackState.hpp"

#include "../StateMachine/StateMachine.hpp"
#include "../IdleState/IdleState.hpp"

#include "../Hero/Hero.hpp"

AttackState::AttackState(StateMachine *stateMachine)
{
    setStateMachine(stateMachine);
    _name = "AttackState";
}

void AttackState::enterState()
{
    std::cout << "Joined " << _name << std::endl;
}

void AttackState::exitState()
{
    std::cout << "Left " << _name << std::endl;
}

void AttackState::update()
{
    _ticks++;

    if (_ticks > 60)
    {
        _stateMachine->setState(new IdleState(_stateMachine));
    }
}