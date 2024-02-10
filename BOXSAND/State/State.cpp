#include "State.hpp"
#include "../Hero/Hero.hpp"

#include <iostream>

State::State()
{
}

void State::enterState()
{
    std::cout << "Joined " << _name << std::endl;
}

void State::exitState()
{
    std::cout << "Left " << _name << std::endl;
}

void State::update(Hero &player)
{
}