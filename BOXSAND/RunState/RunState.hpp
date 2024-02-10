// IdleState.hpp
#ifndef RUN_STATE_HPP
#define RUN_STATE_HPP

#include "../State/State.hpp"

class RunState : public State
{
public:
    RunState();
    ~RunState() {}

    void enterState() override;
    void exitState() override;
    void update(Hero &player) override;
};

#endif