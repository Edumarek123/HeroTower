#include "GameObjects.hpp"

#include <string>

int GameObjects::get_empty_index()
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (_players[i]._uniqueID == -1)
        {
            return i;
        }
    }

    return -1;
}

int GameObjects::get_index(int id)
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (_players[i]._uniqueID == id)
        {
            return i;
        }
    }

    return -1;
}