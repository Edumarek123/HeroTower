#include "GameMapClient.hpp"

GameMapClient::GameMapClient(int screenWidth, int screenHeight, SDL_Renderer *renderer) : GameMap(screenWidth, screenHeight)
{
    // _imagePath = "../../../assets/Map/desert";
    _spriteImage = TextureManager::LoadTexture("assets/Map/desert.png", renderer);
}

void GameMapClient::draw(SDL_Renderer *renderer, int x, int y, int scale)
{
    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    source.w = 800;
    source.h = 450;

    SDL_Rect destine;
    destine.x = 0;
    destine.y = 0;
    destine.w = source.w * scale;
    destine.h = source.h * scale;

        // SDL_RenderCopy(renderer, _spriteImage, &source, &destine);
    // SDL_RenderCopy(renderer, _spriteImage, &source, NULL);
}