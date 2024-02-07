#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../Base/Vector2D/Vector2D.hpp"
#include "../../Base/TextureManager/TextureManager.hpp"

const Vector2D DEFAULT_SPRITE_SIZE(32, 32);

class Sprite
{
public:
    std::string _imagePath;
    SDL_Texture *_spriteImage;

    Vector2D _size;

    Vector2D _maxFrames;
    Vector2D _frame;

    unsigned int _tick = 0;
    unsigned int _maxTicks = 0;
    float _alfaTicks;

    Sprite();
    Sprite(std::string imagePath);
    ~Sprite();

    void setMaxTicks(int newMaxTicks);
    void updateFrameY(int newFrameY);
    void update(int newFrameY);
    void draw(SDL_Renderer *renderer, int x, int y, int scale, bool isFacingLeft, int newFrameY);
};

#endif
