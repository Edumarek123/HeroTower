#include "GameObjects.hpp"

#include <string>

int GameObjects::get_empty_index()
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (std::string(_players[i]._name) == "Entity")
        {
            return i;
        }
    }

    return -1;
}