#ifndef STATE_HPP
#define STATE_HPP

class Hero;

class State
{
public:
    const char *_name = "baseState";

    State();
    virtual ~State() {}

    virtual void enterState(Hero &player);
    virtual void exitState(Hero &player);
    virtual void update(Hero &player);
};

#endif