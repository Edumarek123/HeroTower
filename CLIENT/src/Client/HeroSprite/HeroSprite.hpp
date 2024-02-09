#ifndef HEROSPRITE_HPP
#define HEROSPRITE_HPP

#include <string>
#include "../Sprite/Sprite.hpp"

class HeroSprite : public Sprite
{
public:
    int stateNameToFrameY(const char *stateName);
};

#endif
