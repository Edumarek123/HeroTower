#include "ProjectileClient.hpp"

void ProjectileClient::draw(SDL_Renderer *renderer, int scale)
{
    SDL_Rect box;
    box.x = _position.x * scale;
    box.y = _position.y * scale;
    box.w = _size.x * scale;
    box.h = _size.x * scale;

    SDL_SetRenderDrawColor(renderer, 0, 155, 0, 255);
    SDL_RenderDrawRect(renderer, &box);
    SDL_RenderFillRect(renderer, &box);
}
