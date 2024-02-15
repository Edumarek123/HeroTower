#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>

#include "src/Server/ServerSocket/ServerSocket.hpp"
#include "src/Base/SDerialization/SDerialization.hpp"
#include "src/Base/GameObjects/GameObjects.hpp"
#include "src/Base/GameMap/GameMap.hpp"

int main(void)
{

    ServerSocket server;
    GameObjects OBEJCTS;
    GameMap MAP;

    State **prov;

    prov = (State **)malloc(MAX_PLAYERS * sizeof(State *));

    while (true)
    {
        server.update(OBEJCTS);

        int statsSize = 0;
        for (int i = 0; i < MAX_PLAYERS; i++)
        {
            prov[i] = OBEJCTS._players[i]._stateMachine._currentState;
            OBEJCTS._players[i]._stateMachine._currentState = nullptr;
        }

        char *stats = serialize(OBEJCTS, "GameObjects", statsSize);

        for (int i = 0; i < MAX_PLAYERS; i++)
        {
            OBEJCTS._players[i]._stateMachine._currentState = prov[i];
        }

        for (int i = 0; i < MAX_PLAYERS; i++)
        {
            std::cout << i << ") ";
            if (OBEJCTS._players[i]._uniqueID != -1)
            {
                OBEJCTS._players[i].update(MAP._collisionBLocks, OBEJCTS._keys[i]);

                if (OBEJCTS._projectiles[i]._isActive)
                {
                    OBEJCTS._projectiles[i].update(MAP._collisionBLocks);
                }
                else if (OBEJCTS._keys[i]._n1IsPressed)
                {
                    OBEJCTS._projectiles[i].reset(OBEJCTS._players[i]);
                }

                std::cout << OBEJCTS._players[i]._uniqueID << " " << OBEJCTS._players[i]._name;
            }
            std::cout << std::endl;
        }

        server.broadcastPacket(stats, statsSize);

        free(stats);

        std::cout << std::endl;

        usleep(10000);
    }

    return 0;
}