#include "GameMap.hpp"
#include <iostream>
#include "../Sizes/Sizes.hpp"

GameMap::GameMap()
{
    int k = 0;
    for (int i = 0; i < SCREEN_SIZE.y / TILE_SIZE.y; i++)
    {
        for (int j = 0; j < SCREEN_SIZE.x / TILE_SIZE.x; j++)
        {
            if (i == (SCREEN_SIZE.y / TILE_SIZE.y) - 1)
            {
                _collisionBLocks[k].x = j * TILE_SIZE.x;
                _collisionBLocks[k].y = i * TILE_SIZE.y;
                _collisionBLocks[k].w = TILE_SIZE.x;
                _collisionBLocks[k].h = TILE_SIZE.y;
                k++;
            }
        }
    }
}
