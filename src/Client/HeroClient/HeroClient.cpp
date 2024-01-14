#include "HeroClient.hpp"

#include <iostream>

HeroClient::HeroClient(float x, float y) : Hero(x, y)
{
    _sprite._imagePath = "assets/Hero/hero";

    _weponRightSprite._imagePath = std::string("assets/MeleeWeapons/") + _rightHandWeapon._name;
    _weponLeftSprite._imagePath = std::string("assets/MeleeWeapons/") + _leftHandWeapon._name;
}

void HeroClient::draw(SDL_Renderer *renderer, int scale)
{
    _sprite.draw(renderer, _position.x, _position.y, scale, _isFacingLeft, _sprite.stateNameToFrameY(_stateMachine._currentState->_name));
    _weponRightSprite.draw(renderer, _position, scale, _isFacingLeft, _sprite._frame);
    _weponLeftSprite.draw(renderer, _position, scale, _isFacingLeft, _sprite._frame);
    _healthBarSprite.draw(renderer, _position, scale, _health);
}

void HeroClient::update(const std::vector<Rect4> &blocks)
{
    _controller.update();
    this->Hero::update(blocks, _controller._keys);
}