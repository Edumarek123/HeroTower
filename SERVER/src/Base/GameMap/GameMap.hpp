#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include <vector>

#include "../Rect4/Rect4.hpp"
#include "../GameParameters/GameParameters.hpp"

class GameMap
{
public:
    Rect4 _collisionBLocks[BLOCKS_NUMBER];

    GameMap();
};

#endif