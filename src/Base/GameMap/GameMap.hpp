#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include <vector>

class Rect4;

class GameMap
{
public:
    std::vector<Rect4> _collisionBLocks;

    GameMap(int screenWidth, int screenHeight);
};

#endif