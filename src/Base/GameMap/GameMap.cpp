#include "GameMap.hpp"
#include "../Rect4/Rect4.hpp"
#include <iostream>

GameMap::GameMap(int screenWidth, int screenHeight)
{
    // _collisionBLocks = collisionBLocks;

    for (int i = 0; i < screenHeight / 32; i++)
    {
        for (int j = 0; j < screenWidth / 32; j++)
        {
            Rect4 block = Rect4(j * 32, i * 32, 32, 32);

            if (i == (screenHeight / 32) - 1)
            {

                _collisionBLocks.emplace_back(block);
            }
        }
    }
    Rect4 block = Rect4(0, 8 * 32, 32, 32);
    _collisionBLocks.emplace_back(block);
    block.y = 7 * 32;
    _collisionBLocks.emplace_back(block);
    block.y = 6 * 32;
    _collisionBLocks.emplace_back(block);

    block.y = 8 * 32;
    block.x = 3 * 32;
    _collisionBLocks.emplace_back(block);
    block.y = 7 * 32;
    _collisionBLocks.emplace_back(block);
    block.y = 8 * 32;
    block.x = 4 * 32;
    _collisionBLocks.emplace_back(block);
}
