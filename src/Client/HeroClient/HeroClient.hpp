#ifndef HEROCLIENT_HPP
#define HEROCLIENT_HPP

#include "../../Hero/Hero.hpp"
#include "../PlayerController/PlayerController.hpp"
#include "../Sprite/Sprite.hpp"

class HeroClient : public Hero
{
public:
    PlayerController _controller;
    Sprite _sprite;

    HeroClient(float x, float y) : Hero(x, y) {}
    using Hero::update;
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
