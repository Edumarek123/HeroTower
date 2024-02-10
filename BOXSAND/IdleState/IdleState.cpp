#include "IdleState.hpp"
#include "../RunState/RunState.hpp"

#include "../Hero/Hero.hpp"

#include <iostream>

IdleState::IdleState()
{
    _name = "IdleState";
}

void IdleState::enterState()
{
    std::cout << "Joined " << _name << std::endl;
}

void IdleState::exitState()
{
    std::cout << "Left " << _name << std::endl;
}

void IdleState::update(Hero &player)
{

    player._stateMachine.setState(new RunState());
}