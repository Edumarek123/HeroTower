#include "RunState.hpp"
#include "../IdleState/IdleState.hpp"

#include "../Hero/Hero.hpp"

#include <iostream>

RunState::RunState()
{
    _name = "RunState";
}

void RunState::enterState()
{
    std::cout << " Joined " << _name << std::endl;
}

void RunState::exitState()
{
    std::cout << "Left " << _name << std::endl;
}

void RunState::update(Hero &player)
{
    player._stateMachine.setState(new IdleState());
}