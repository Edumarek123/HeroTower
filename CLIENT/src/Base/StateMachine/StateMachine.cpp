#include "StateMachine.hpp"
#include "../Hero/Hero.hpp"

#include <cstring>

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
}

void StateMachine::setState(State *newState, Hero &player)
{
    // _currentState[0].exitState(player);

    // memcpy(&_currentState[0], newState, sizeof(_currentState));

    // delete newState;

    // _currentState[0].enterState(player);
}

void StateMachine::update(Hero &player)
{
    // _currentState[0].update(player);
}