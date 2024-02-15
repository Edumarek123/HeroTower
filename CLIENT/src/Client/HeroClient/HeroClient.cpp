#include "HeroClient.hpp"

#include <iostream>

HeroClient::HeroClient() : Hero(0.0f, 0.0f)
{
    _sprite._imagePath = "assets/Hero/hero_base";

    _weponRightSprite._imagePath = std::string("assets/MeleeWeapons/") + _rightHandWeapon._name;
    _weponLeftSprite._imagePath = std::string("assets/MeleeWeapons/") + _leftHandWeapon._name;
}

HeroClient::HeroClient(float x, float y) : Hero(x, y)
{
    _sprite._imagePath = "assets/Hero/base_hero";

    _weponRightSprite._imagePath = std::string("assets/MeleeWeapons/") + _rightHandWeapon._name;
    _weponLeftSprite._imagePath = std::string("assets/MeleeWeapons/") + _leftHandWeapon._name;
}

void HeroClient::draw(SDL_Renderer *renderer, int scale)
{
    _sprite._imagePath = "assets/Hero/base_hero";
    _sprite.draw(renderer, _position.x, _position.y, scale, _isFacingLeft, _stateMachine._Estate);

    // _weponRightSprite.draw(renderer, _position, scale, _isFacingLeft, _sprite._frame);
    // _weponLeftSprite.draw(renderer, _position, scale, _isFacingLeft, _sprite._frame);
    _healthBarSprite.draw(renderer, _position, scale, _health);
}

void HeroClient::update(const Rect4 *blocks, PlayerKeys newKeys)
{
    this->Hero::update(blocks, newKeys);
}