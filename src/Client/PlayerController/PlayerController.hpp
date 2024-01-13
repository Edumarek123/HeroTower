#ifndef PLAYERCONTROLLER_HPP
#define PLAYERCONTROLLER_HPP

#include <SDL2/SDL.h>

#include "../../Base/PlayerKeys/PlayerKeys.hpp"

class PlayerController
{
public:
    PlayerKeys _keys;

    PlayerController();
    void update();
};

#endif