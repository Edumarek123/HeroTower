#include "FiniteStateMachine.hpp"

void FiniteStateMachine::update(Hero hero, newState)
{
    _state.exitState(hero);
    _state = newState;
    _state.enterState(hero);
}