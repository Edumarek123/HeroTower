#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include "src/ServerSocket/ServerSocket.hpp"

std::vector<Hero *> PLAYERS;

int main(int argc, char **argv)
{
    ServerSocket server;

    while (true)
    {
        server.update(PLAYERS);

        for (auto &player : PLAYERS)
        {
            std::cout << player->_name << std::endl;
        }
        std::cout << std::endl;

        // usleep(10);
    }

    return EXIT_SUCCESS;
}