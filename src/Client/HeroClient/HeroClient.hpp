#ifndef HEROCLIENT_HPP
#define HEROCLIENT_HPP

#include "../../Base/Hero/Hero.hpp"
#include "../PlayerController/PlayerController.hpp"
#include "../HeroSprite/HeroSprite.hpp"
#include "../WeaponSprite/WeaponSprite.hpp"
#include "../HealthBarSprite/HealthBarSprite.hpp"
#include "../../Base/Rect4/Rect4.hpp"

class HeroClient : public Hero
{
public:
    PlayerController _controller;

    HeroSprite _sprite;
    HealthBarSprite _healthBarSprite;
    WeaponSprite _weponRightSprite;
    WeaponSprite _weponLeftSprite;

    HeroClient(float x, float y);
    void update(const std::vector<Rect4> &blocks);
    void draw(SDL_Renderer *renderer, int scale);
};

#endif

// constructor(_x, _y, _w, _h, _n, _sl, _sk)
// {
//     super(_x, _y, _w, _h, _n);

//     this.sprite = new HeroSprite(this.weapons.baseSpeed);

//     this.rightWeaponSprites = new WeaponSprite(this.itens.weapons.right);
//     this.leftWeaponSprites = new WeaponSprite(this.itens.weapons.left);

//     this.healthBar = new HealthBar(this.stats.health);

// }
