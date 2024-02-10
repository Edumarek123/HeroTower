#include <iostream>
#include <vector>
#include <cstring>

#include "src/Server/ServerSocket/ServerSocket.hpp"
#include "src/Base/SDerialization/SDerialization.hpp"
#include "src/Base/GameObjects/GameObjects.hpp"
#include "src/Base/GameMap/GameMap.hpp"

int main(void)
{

    ServerSocket server;
    GameObjects OBEJCTS;
    GameMap MAP;

    while (true)
    {
        server.update(OBEJCTS);

        int statsSize = 0;
        char *stats = serialize(OBEJCTS, "GameObjects", statsSize);

        for (int i = 0; i < MAX_PLAYERS; i++)
        {
            OBEJCTS._players[i].update(MAP._collisionBLocks, OBEJCTS._keys[i]);

            std::cout << i << ") " << OBEJCTS._players[i]._name << std::endl;
        }

        server.broadcastPacket(stats, statsSize);

        free(stats);

        std::cout << std::endl;
    }

    return 0;
}