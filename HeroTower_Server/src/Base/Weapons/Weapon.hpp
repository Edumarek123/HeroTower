#ifndef WEAPON_HPP
#define WEAPON_HPP

struct Weapon
{
    float _baseDamage;
    float _baseSpeed;
    float _baseMass;
    const char *_name;

    // Weapon &operator=(Weapon const &w);

    Weapon();
    Weapon(float baseDamage, float baseSpeed, float baseMass, const char *name);
};

#endif