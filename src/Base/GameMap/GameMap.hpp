#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include <vector>

#include "../Rect4/Rect4.hpp"

class GameMap
{
public:
    std::vector<Rect4> _collisionBLocks;

    GameMap(int screenWidth, int screenHeight);
};

#endif