#ifndef WEAPON_SPRITE_HPP
#define WEAPON_SPRITE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Sprite/Sprite.hpp"

class Weapon;

class WeaponSprite : public Sprite
{
public:
    using Sprite::Sprite;
    void draw(SDL_Renderer *renderer, Vector2D position, int scale, bool isFacingLeft, Vector2D frame);
};

#endif