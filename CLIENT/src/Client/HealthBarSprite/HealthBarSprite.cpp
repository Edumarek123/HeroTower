#include "HealthBarSprite.hpp"

void HealthBarSprite::draw(SDL_Renderer *renderer, Vector2D position, int scale, float health)
{
    // border
    SDL_Rect bar;
    bar.x = (position.x - _size.y / 2) * scale;
    bar.y = (position.y - (1.5 * _size.y)) * scale;
    bar.w = (_size.x + _size.y) * scale;
    bar.h = 2 * _size.y * scale;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &bar);
    SDL_RenderFillRect(renderer, &bar);

    // Background
    bar.x = position.x * scale;
    bar.y = (position.y - _size.y) * scale;
    bar.w = _size.x * scale;
    bar.h = _size.y * scale;
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &bar);
    SDL_RenderFillRect(renderer, &bar);

    // health
    bar.x = position.x * scale;
    bar.y = (position.y - _size.y) * scale;
    bar.w = _size.x * health * scale;
    bar.h = _size.y * scale;
    SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &bar);
    SDL_RenderFillRect(renderer, &bar);
}