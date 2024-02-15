// FallingState.hpp
#ifndef ATTACKSTATE_HPP
#define ATTACKSTATE_HPP

#include "../State/State.hpp"

class AttackState : public State
{
public:
    AttackState();
    ~AttackState() {}

    void enterState(Hero &player) override;
    void exitState(Hero &player) override;
    void update(Hero &player, int &_ticks) override;
};

#endif