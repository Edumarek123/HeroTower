// IdleState.hpp
#ifndef RUN_STATE_HPP
#define RUN_STATE_HPP

#include "../State/State.hpp"
#include <iostream>

class StateMachine;

class RunState : public State
{
public:
    RunState(StateMachine *stateMachine);
    ~RunState() {}

    void enterState() override;
    void exitState() override;
    void update() override;
};

#endif