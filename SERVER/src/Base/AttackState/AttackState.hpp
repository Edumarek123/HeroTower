// FallingState.hpp
#ifndef ATTACKSTATE_HPP
#define ATTACKSTATE_HPP

#include "../State/State.hpp"
#include <iostream>

class StateMachine;

class AttackState : public State
{
public:
    int _ticks = 0;

    AttackState(StateMachine *stateMachine);
    ~AttackState() {}

    void enterState() override;
    void exitState() override;
    void update() override;
};

#endif