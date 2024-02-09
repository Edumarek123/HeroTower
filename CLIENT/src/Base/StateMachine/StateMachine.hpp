#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

class Hero;
class State;

class StateMachine
{
public:
    State *_currentState;
    Hero *_hero;

    StateMachine();
    ~StateMachine();

    void setState(State *newState);
    void setHero(Hero *newHero);
    void update();
};
#endif