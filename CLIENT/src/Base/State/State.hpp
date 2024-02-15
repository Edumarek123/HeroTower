#ifndef STATE_HPP
#define STATE_HPP

class Hero;

class State
{
public:
    int _tag = -1;

    State();
    virtual ~State() {}

    virtual void enterState(Hero &player);
    virtual void exitState(Hero &player);
    virtual void update(Hero &player, int &_ticks);
};

#endif