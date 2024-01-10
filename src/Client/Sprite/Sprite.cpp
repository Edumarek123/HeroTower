#include "Sprite.hpp"
Sprite::Sprite()
{
    _imagePath = "";

    _size = Vector2D(32 * 4, 32 * 4); // mudar

    _maxFrames.x = _size.x / DEFAULT_SPRITE_SIZE.x;
    _maxFrames.y = _size.y / DEFAULT_SPRITE_SIZE.y;

    _maxTicks = 10;
    _alfaTicks = (_maxFrames.x - 1) / _maxTicks;
}

Sprite::Sprite(std::string imagePath)
{
    _imagePath = imagePath;

    _size = Vector2D(32 * 4, 32 * 4); // mudar

    _maxFrames.x = _size.x / DEFAULT_SPRITE_SIZE.x;
    _maxFrames.y = _size.y / DEFAULT_SPRITE_SIZE.y;

    _maxTicks = 10;
    _alfaTicks = (_maxFrames.x - 1) / _maxTicks;
}

Sprite::~Sprite()
{
}

void Sprite::setMaxTicks(int newMaxTicks)
{
    _maxTicks = newMaxTicks;
    _alfaTicks = (_maxFrames.x - 1) / _maxTicks;
}

void Sprite::updateFrameY(int newFrameY)
{
    if (_frame.y != newFrameY)
    {
        _tick = 0;
        _frame.x = 0;
        _frame.y = newFrameY;
    }
}

void Sprite::update(int newFrameY)
{
    _frame.x = _tick * _alfaTicks;
    _tick++;

    if (_frame.x > _maxFrames.x - 1)
    {
        _frame.x = 0;
        _tick = 0;
    }
    updateFrameY(newFrameY);
}

void Sprite::draw(SDL_Renderer *renderer, int x, int y, int scale, bool isFacingLeft, int newFrameY)
{
    update(newFrameY);

    SDL_Rect a;
    a.y = DEFAULT_SPRITE_SIZE.y * _frame.y;
    a.w = DEFAULT_SPRITE_SIZE.x;
    a.h = DEFAULT_SPRITE_SIZE.y;

    SDL_Rect b;
    b.x = x * scale;
    b.y = y * scale;
    b.w = DEFAULT_SPRITE_SIZE.x * scale;
    b.h = DEFAULT_SPRITE_SIZE.y * scale;

    if (isFacingLeft)
    {
        a.x = (_maxFrames.x - (int)_frame.x - 1) * DEFAULT_SPRITE_SIZE.x;
        _spriteImage = TextureManager::LoadTexture((_imagePath + "Left.png").c_str(), renderer);
    }
    else
    {
        a.x = DEFAULT_SPRITE_SIZE.x * (int)_frame.x;
        _spriteImage = TextureManager::LoadTexture((_imagePath + "Right.png").c_str(), renderer);
    }
    SDL_RenderCopy(renderer, _spriteImage, &a, &b);
}
