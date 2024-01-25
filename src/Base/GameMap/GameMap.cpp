#include "GameMap.hpp"
#include <iostream>
#include "../Sizes/Sizes.hpp"

GameMap::GameMap(int screenWidth, int screenHeight)
{
    // _collisionBLocks = collisionBLocks;

    for (int i = 0; i < screenHeight / TILE_SIZE.y; i++)
    {
        for (int j = 0; j < screenWidth / TILE_SIZE.x; j++)
        {
            Rect4 block = Rect4(j * TILE_SIZE.x, i * TILE_SIZE.y, TILE_SIZE.x, TILE_SIZE.y);

            if (i == (screenHeight / TILE_SIZE.y) - 1)
            {

                _collisionBLocks.emplace_back(block);
            }
        }
    }
}
