#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <vector>
#include "../Vector2D/Vector2D.hpp"
#include "../Rect4/Rect4.hpp"

class Entity
{
public:
    // atributes
    std::string _name;
    // Stats _stats;

    // physics
    Vector2D _position;
    Vector2D _velocity;
    Vector2D _accelerataion;
    float _maxVelocity = 5;
    float _maxAccelerataion = 5;
    Vector2D _size;

    // states
    bool _isGrounded = false;
    bool _isFacingLeft = false;

    // constructor
    Entity(float x, float y);
    ~Entity();

    // methods
    void update(std::vector<Rect4> blocks);
    void blockCollisions(std::vector<Rect4> blocks);
    void input(Vector2D f);
    void applyFriction();
};

#endif