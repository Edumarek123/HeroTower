#ifndef HEROCLIENT_HPP
#define HEROCLIENT_HPP

#include "../../Base/Hero/Hero.hpp"
#include "../Sprite/Sprite.hpp"
#include "../WeaponSprite/WeaponSprite.hpp"
#include "../HealthBarSprite/HealthBarSprite.hpp"
#include "../../Base/Rect4/Rect4.hpp"

class HeroClient : public Hero
{
public:
    Sprite _sprite;
    HealthBarSprite _healthBarSprite;
    WeaponSprite _weponRightSprite;
    WeaponSprite _weponLeftSprite;

    HeroClient();
    HeroClient(float x, float y);
    void update(const Rect4 *blocks, PlayerKeys newKeys);
    void draw(SDL_Renderer *renderer, int scale);
};

#endif