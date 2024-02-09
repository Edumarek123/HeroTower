#include <iostream>
#include <vector>
#include <cstring>

#include "src/Server/ServerSocket/ServerSocket.hpp"
#include "src/Base/SDerialization/SDerialization.hpp"
#include "src/Base/GameObjects/GameObjects.hpp"

int main(int argc, char **argv)
{
    // ServerSocket server;
    GameObjects OBEJCTS;

    std::cout << sizeof(OBEJCTS) << std::endl;

    // while (true)
    {
        // server.update(OBEJCTS);

        // int statsSize = 0;
        // char *stats = serialize(OBEJCTS, "GameObjects", statsSize);
        // std::cout << statsSize << std::endl;
        // server.broadcastPacket(stats, statsSize);
        // free(stats);

        // usleep(10);
    }

    return EXIT_SUCCESS;
}