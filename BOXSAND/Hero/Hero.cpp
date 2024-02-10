#include "Hero.hpp"

#include "../IdleState/IdleState.hpp"
#include "../RunState/RunState.hpp"

Hero::Hero()
{
    _x = 0;
    _y = 0;

    _stateMachine.setState(new IdleState());
}

Hero::Hero(int x, int y) : _x(x), _y(y)
{
    _stateMachine.setState(new IdleState());
}

void Hero::update()
{
    _stateMachine.update(*this);
}