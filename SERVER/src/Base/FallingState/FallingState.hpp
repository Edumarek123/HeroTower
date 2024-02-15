// FallingState.hpp
#ifndef FALLINGSTATE_HPP
#define FALLINGSTATE_HPP

#include "../State/State.hpp"

class FallingState : public State
{
public:
    FallingState();
    ~FallingState() {}

    void enterState(Hero &player) override;
    void exitState(Hero &player) override;
    void update(Hero &player, int &_ticks) override;
};

#endif