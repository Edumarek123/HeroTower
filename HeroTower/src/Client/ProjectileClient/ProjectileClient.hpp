#ifndef PROJECTILECLIENT_HPP
#define PROJECTILECLIENT_HPP

#include "../../Base/Projectile/Projectile.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ProjectileClient : public Projectile
{
public:
    using Projectile::Projectile;
    void draw(SDL_Renderer *renderer, int scale);
};

#endif