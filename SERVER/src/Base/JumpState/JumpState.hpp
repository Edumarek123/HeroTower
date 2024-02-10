// JumpState.hpp
#ifndef JUMPSTATE_HPP
#define JUMPSTATE_HPP

#include "../State/State.hpp"

class JumpState : public State
{
public:
    JumpState();
    ~JumpState() {}

    void enterState(Hero &player) override;
    void exitState(Hero &player) override;
    void update(Hero &player) override;
};

#endif