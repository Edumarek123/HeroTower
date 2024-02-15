#include "GameMapClient.hpp"
#include "../../Base/Sizes/Sizes.hpp"

GameMapClient::GameMapClient(SDL_Renderer *renderer)
{
    // _imagePath = "../../assets/Map/desert";
    _spriteImage = TextureManager::LoadTexture("assets/Map/desert.png", renderer);
}

void GameMapClient::draw(SDL_Renderer *renderer, int x, int y, int scale)
{
    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    source.w = SCREEN_SIZE.x;
    source.h = SCREEN_SIZE.y;

    SDL_Rect destine;
    destine.x = 0;
    destine.y = 0;
    destine.w = source.w * scale;
    destine.h = source.h * scale;

    SDL_SetRenderDrawColor(renderer, 34, 35, 35, 255);
    SDL_RenderDrawRect(renderer, &destine);
    SDL_RenderFillRect(renderer, &destine);

    for (int i = 0; i < BLOCKS_NUMBER; i++)
    {
        SDL_Rect b;
        b.x = _collisionBLocks[i].x * scale;
        b.y = _collisionBLocks[i].y * scale;
        b.w = _collisionBLocks[i].w * scale;
        b.h = _collisionBLocks[i].h * scale;

        SDL_SetRenderDrawColor(renderer, 155, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &b);
        SDL_RenderFillRect(renderer, &b);
    }

    // SDL_RenderCopy(renderer, _spriteImage, &source, &destine);
    // SDL_RenderCopy(renderer, _spriteImage, &source, NULL);
}