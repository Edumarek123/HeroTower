#ifndef PLAYERCONTROLLER_HPP
#define PLAYERCONTROLLER_HPP

#include "../../Base/PlayerKeys/PlayerKeys.hpp"

class PlayerController
{
public:
    PlayerKeys _keys;

    PlayerController();
    void update();
};

#endif