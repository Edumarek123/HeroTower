#ifndef HERO_HPP
#define HERO_HPP

#include <vector>
#include "../Entity/Entity.hpp"
#include "../PlayerKeys/PlayerKeys.hpp"
#include "../StateMachine/StateMachine.hpp"
#include "../IdleState/IdleState.hpp"
#include "../RunState/RunState.hpp"
#include "../Weapons/Weapon.hpp"

class Hero : public Entity
{
public:
    std::vector<std::string> _itens;

    Weapon _rightHandWeapon;
    Weapon _leftHandWeapon;
    StateMachine _stateMachine;

    PlayerKeys _keys;

    Hero(float x, float y);

    void update(const std::vector<Rect4> &blocks, PlayerKeys newKeys);
};

#endif