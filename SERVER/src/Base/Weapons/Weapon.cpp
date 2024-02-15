#include "Weapon.hpp"
#include <string.h>
#include <stdlib.h>

Weapon::Weapon()
{
    _baseDamage = 1.0f;
    _baseSpeed = 1.0f;
    _baseMass = 1.0f;
}

Weapon::Weapon(float baseDamage, float baseSpeed, float baseMass, const char *name) : _baseDamage(baseDamage), _baseSpeed(baseSpeed), _baseMass(baseMass)
{
    strcpy(_name, name);
}

// one handed
const Weapon oneHandSword(1, 40, 1, "oneHandSword");
const Weapon oneHandAxe(1, 60, 1, "oneHandAxe");
const Weapon oneHandDagger(1, 20, 1, "oneHandDagger");
const Weapon oneHandHammer(1, 70, 1, "oneHandHammer");

// two handed
const Weapon twoHandSword(1, 100, 1, "TwoHandSword");
const Weapon twoHandAxe(1, 110, 1, "twoHandAxe");
const Weapon twoHandHammer(1, 120, 1, "twoHandHammer");
const Weapon twoHandSpear(1, 95, 1, "twoHandSpear");