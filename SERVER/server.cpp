#include <iostream>
#include <vector>
#include <cstring>

#include "src/Server/ServerSocket/ServerSocket.hpp"
#include "src/Base/SDerialization/SDerialization.hpp"
#include "src/Base/GameObjects/GameObjects.hpp"

int main(void)
{
    ServerSocket server;
    GameObjects OBEJCTS;

    while (true)
    {
        server.update(OBEJCTS);

        int statsSize = 0;
        char *stats = serialize(OBEJCTS, "GameObjects", statsSize);

        server.broadcastPacket(stats, statsSize);

        free(stats);

        for (int i = 0; i < MAX_PLAYERS; i++)
        {
            std::cout << i << ") " << OBEJCTS._players[i]._name << std::endl;
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}