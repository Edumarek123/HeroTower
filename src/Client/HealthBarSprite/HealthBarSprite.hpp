#ifndef HEALTHBARSPRITE_HPP
#define HEALTHBARSPRITE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../Base/Vector2D/Vector2D.hpp"

class HealthBarSprite
{
public:
    Vector2D _size = Vector2D(32, 2);

    void draw(SDL_Renderer *renderer, Vector2D position, int scale, float health);
};

#endif