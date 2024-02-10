#include <iostream>

#include "Hero/Hero.hpp"

int main(void)
{

    Hero player(1, 5);

    player.update();
    player.update();

    return 0;
}