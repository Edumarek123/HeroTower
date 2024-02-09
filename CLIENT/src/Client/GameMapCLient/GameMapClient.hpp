#ifndef GAMEMAPCLIENT_HPP
#define GAMEMAPCLIENT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../Base/GameMap/GameMap.hpp"
#include "../Sprite/Sprite.hpp"
#include "../../Base/TextureManager/TextureManager.hpp"

class GameMapClient : public GameMap
{
public:
    std::string _imagePath;
    SDL_Texture *_spriteImage;

    GameMapClient(SDL_Renderer *renderer);

    void draw(SDL_Renderer *renderer, int x, int y, int scale);
};

#endif