// IdleState.hpp
#ifndef RUN_STATE_HPP
#define RUN_STATE_HPP

#include "../State/State.hpp"

class RunState : public State
{
public:
    RunState();
    ~RunState() {}

    void enterState(Hero &player) override;
    void exitState(Hero &player) override;
    void update(Hero &player) override;
};

#endif