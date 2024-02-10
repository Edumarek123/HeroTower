// FallingState.hpp
#ifndef ATTACKSTATE_HPP
#define ATTACKSTATE_HPP

#include "../State/State.hpp"

class AttackState : public State
{
public:
    int _ticks = 0;

    AttackState();
    ~AttackState() {}

    void enterState(Hero &player) override;
    void exitState(Hero &player) override;
    void update(Hero &player) override;
};

#endif