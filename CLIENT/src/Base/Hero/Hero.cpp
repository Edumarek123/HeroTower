#include "Hero.hpp"

Hero::Hero() : Entity(0.0f, 0.0f)
{
    _stateMachine.setState(new IdleState(&_stateMachine));
    _stateMachine.setHero(this);

    _rightHandWeapon = Weapon(1, 40, 1, "oneHandSword");
    _leftHandWeapon = Weapon(1, 40, 1, "oneHandAxeOff");
}

Hero::Hero(float x, float y) : Entity(x, y)
{
    _stateMachine.setState(new IdleState(&_stateMachine));
    _stateMachine.setHero(this);

    _rightHandWeapon = Weapon(1, 40, 1, "oneHandSword");
    _leftHandWeapon = Weapon(1, 40, 1, "oneHandAxeOff");
}

void Hero::update(const std::vector<Rect4> &blocks, PlayerKeys newKeys)
{
    _keys = newKeys;
    this->Entity::update(blocks);

    _stateMachine.update();
}