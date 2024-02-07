#include "WeaponSprite.hpp"

#include <cmath>

void WeaponSprite::draw(SDL_Renderer *renderer, Vector2D position, int scale, bool isFacingLeft, Vector2D frame)
{
    SDL_Rect source;
    source.y = DEFAULT_SPRITE_SIZE.y * frame.y;
    source.w = DEFAULT_SPRITE_SIZE.x;
    source.h = DEFAULT_SPRITE_SIZE.y;

    SDL_Rect destine;
    destine.x = position.x * scale;
    destine.y = position.y * scale;
    destine.w = DEFAULT_SPRITE_SIZE.x * scale;
    destine.h = DEFAULT_SPRITE_SIZE.y * scale;

    if (isFacingLeft)
    {
        source.x = (_maxFrames.x - round(frame.x) - 1) * DEFAULT_SPRITE_SIZE.x;
        _spriteImage = TextureManager::LoadTexture((_imagePath + "Left.png").c_str(), renderer);
    }
    else
    {
        source.x = DEFAULT_SPRITE_SIZE.x * round(frame.x);
        _spriteImage = TextureManager::LoadTexture((_imagePath + "Right.png").c_str(), renderer);
    }
    SDL_RenderCopy(renderer, _spriteImage, &source, &destine);
}