#include "HeroSprite.hpp"

int HeroSprite::stateNameToFrameY(const char *stateName)
{
    std::string compareName(stateName);

    if (compareName == "IdleState")
    {
        return 0;
    }
    else if (compareName == "RunState")
    {
        return 1;
    }
    else if (compareName == "JumpState")
    {
        return 2;
    }
    else if (compareName == "AtackState")
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
