#include "Hero.hpp"

Hero::Hero() : Entity(0.0f, 0.0f)
{
    _rightHandWeapon = Weapon(1, 40, 1, "oneHandSword");
    _leftHandWeapon = Weapon(1, 40, 1, "oneHandAxeOff");

    // _stateMachine.setState(new IdleState(), *this);
}

Hero::Hero(float x, float y) : Entity(x, y)
{
    _rightHandWeapon = Weapon(1, 40, 1, "oneHandSword");
    _leftHandWeapon = Weapon(1, 40, 1, "oneHandAxeOff");

    // _stateMachine.setState(new IdleState(), *this);
}

void Hero::copy(const Hero &h)
{
    this->Entity::copy(h);

    _rightHandWeapon = h._rightHandWeapon;
    _leftHandWeapon = h._leftHandWeapon;
    // _stateMachine = h._stateMachine;

    _keys = h._keys;
}

void Hero::update(const Rect4 *blocks, PlayerKeys newKeys)
{
    _keys = newKeys;
    this->Entity::update(blocks);

    // _stateMachine.update(*this);
}