#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "../StatesList/StatesList.hpp"

class State;
class Hero;

class StateMachine
{
public:
    State *_currentState = nullptr;
    int _Estate;
    int _stateTick = 0;

    StateMachine();
    ~StateMachine();

    void setState(State *newState, Hero &player);
    void restore_state(eMachineStates state, int tick);
    eMachineStates select_eState(const char *stateName);
    void update(Hero &player);
};

#endif