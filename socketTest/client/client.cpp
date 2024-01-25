#include <iostream>

#include "src/ClientSocket/ClientSocket.hpp"

int main(int argc, char **argv)
{

    ClientSocket client;
    std::cout << "tentando" << std::endl;

    client.sendPacket("oi estou testando");

    while (true)
    {
        client.update();
    }

    return EXIT_SUCCESS;
}
