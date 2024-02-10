#include "StateMachine.hpp"

#include <cstring>
#include <iostream>

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
}

void StateMachine::setState(State *newState)
{
    _currentState[0].exitState();

    memcpy(&_currentState[0], newState, sizeof(_currentState));

    delete newState;

    _currentState[0].enterState();
}

void StateMachine::update(Hero &player)
{
    _currentState[0].update(player);
}