#ifndef HERO_HPP
#define HERO_HPP

#include "../Entity/Entity.hpp"
#include "../PlayerKeys/PlayerKeys.hpp"
#include "../StateMachine/StateMachine.hpp"
#include "../IdleState/IdleState.hpp"
#include "../RunState/RunState.hpp"
#include "../Weapons/Weapon.hpp"

class Hero : public Entity
{
public:
    Weapon _rightHandWeapon;
    Weapon _leftHandWeapon;
    StateMachine _stateMachine;

    PlayerKeys _keys;

    Hero();
    Hero(float x, float y);

    void copy(const Hero &h);
    void update(const Rect4 *blocks, PlayerKeys newKeys);
};

#endif