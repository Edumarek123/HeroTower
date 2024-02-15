#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *path, SDL_Renderer *renderer)
    {
        SDL_Surface *tempSurface = IMG_Load(path);
        SDL_Texture *image = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        return image;
    }
};

#endif