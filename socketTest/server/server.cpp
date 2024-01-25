#include <iostream>
#include <string>

#include "src/ServerSocket/ServerSocket.hpp"

int main(int argc, char **argv)
{
    ServerSocket server;

    while (true)
    {

        server.update();
    }

    return EXIT_SUCCESS;
}
