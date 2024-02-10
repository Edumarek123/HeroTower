#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "../State/State.hpp"

class Hero;

class StateMachine
{
public:
    // State _currentState[1];

    StateMachine();
    ~StateMachine();

    void setState(State *newState, Hero &player);
    void update(Hero &player);
};
#endif