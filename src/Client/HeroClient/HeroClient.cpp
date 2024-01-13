#include "HeroClient.hpp"

#include <iostream>

void HeroClient::draw(SDL_Renderer *renderer, int scale)
{
    _sprite.draw(renderer, _position.x, _position.y, scale, _isFacingLeft, _sprite.stateNameToFrameY(_stateMachine._currentState->_name));
}

void HeroClient::update(const std::vector<Rect4> &blocks)
{
    _controller.update();
    this->Hero::update(blocks, _controller._keys);
}