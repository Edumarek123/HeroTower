// JumpState.hpp
#ifndef JUMPSTATE_HPP
#define JUMPSTATE_HPP

#include "../StateMachine/StateMachine.hpp"
#include "../State/State.hpp"
#include <iostream>

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