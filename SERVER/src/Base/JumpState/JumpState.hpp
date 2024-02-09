// JumpState.hpp
#ifndef JUMPSTATE_HPP
#define JUMPSTATE_HPP

#include <iostream>
#include "../State/State.hpp"

class StateMachine;

class JumpState : public State
{
public:
    JumpState(StateMachine *stateMachine);
    ~JumpState() {}

    void enterState() override;
    void exitState() override;
    void update() override;
};

#endif