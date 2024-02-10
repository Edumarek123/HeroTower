#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <iostream>

#include <string>

#include "../Vector2D/Vector2D.hpp"
#include "../Rect4/Rect4.hpp"

class Entity
{
public:
    // atributes
    char _name[32] = "Entity";
    // Stats _stats;
    float _health = 0.6;

    // physics
    Vector2D _position;
    Vector2D _velocity;
    Vector2D _accelerataion;
    float _maxVelocity = 5;
    float _maxAccelerataion = 5;
    Vector2D _size = Vector2D(32.0f, 32.0f);

    // states
    bool _isGrounded = false;
    bool _isFacingLeft = false;

    // constructor
    Entity();
    Entity(float x, float y);
    ~Entity();

    // methods
    void copy(const Entity &e);
    void update(const Rect4 *blocks);
    void blockCollisions(const Rect4 *blocks);
    void input(Vector2D f);
    void applyFriction();
};

bool colisionDetec(Rect4 s, Rect4 t);

#endif