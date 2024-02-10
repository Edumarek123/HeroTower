#ifndef HERO_HPP
#define HERO_HPP

#include "../StateMachine/StateMachine.hpp"

class Hero
{
public:
    int _x;
    int _y;
    StateMachine _stateMachine;

    Hero();
    Hero(int x, int y);

    void update();
};

#endif