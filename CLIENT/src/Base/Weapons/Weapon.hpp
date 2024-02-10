#ifndef WEAPON_HPP
#define WEAPON_HPP

struct Weapon
{
    float _baseDamage;
    float _baseSpeed;
    float _baseMass;
    char _name[32];

    Weapon();
    Weapon(float baseDamage, float baseSpeed, float baseMass, const char *name);
};

#endif