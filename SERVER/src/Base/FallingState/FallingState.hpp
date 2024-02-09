// FallingState.hpp
#ifndef FALLINGSTATE_HPP
#define FALLINGSTATE_HPP

#include "../State/State.hpp"
#include <iostream>

class StateMachine;

class FallingState : public State
{
public:
    FallingState(StateMachine *stateMachine);
    ~FallingState() {}

    void enterState() override;
    void exitState() override;
    void update() override;
};

#endif