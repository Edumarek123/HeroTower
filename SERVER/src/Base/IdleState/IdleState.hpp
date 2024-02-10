// IdleState.hpp
#ifndef IDLE_STATE_HPP
#define IDLE_STATE_HPP

#include "../State/State.hpp"

class IdleState : public State
{
public:
    IdleState();
    ~IdleState() {}

    void enterState(Hero &player) override;
    void exitState(Hero &player) override;
    void update(Hero &player) override;
};

#endif