#include "GameObjects.hpp"

int GameObjects::get_empty_index()
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (_players[i]._name == "Entity")
        {
            return i;
        }
    }

    return -1;
}