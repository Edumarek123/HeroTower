#include "Entity.hpp"
#include <cmath>
#include <string.h>
#include "../GameParameters/GameParameters.hpp"

Entity::Entity()
{
    _position.x = 0;
    _position.y = 0;
}

Entity::Entity(float x, float y)
{
    _position.x = x;
    _position.y = y;
}

Entity::~Entity()
{
}

void Entity::copy(const Entity &e)
{
    // atributes
    strcpy(_name, e._name);
    // Stats _stats;
    _health = e._health;

    // physics
    _position = e._position;
    _velocity = e._velocity;
    _accelerataion = e._accelerataion;
    _maxVelocity = e._maxVelocity;
    _maxAccelerataion = _maxAccelerataion;
    _size = e._size;

    // states
    _isGrounded = e._isGrounded;
    _isFacingLeft = e._isFacingLeft;
}

void Entity::update(const Rect4 *blocks)
{
    _accelerataion.y += 1;

    _velocity += _accelerataion;

    if (_velocity.x > _maxVelocity)
    {
        _velocity.x = _maxVelocity;
    }

    if (_velocity.x < -_maxVelocity)
    {
        _velocity.x = -_maxVelocity;
    }

    _velocity.x = (int)_velocity.x;
    _velocity.y = (int)_velocity.y;

    blockCollisions(blocks);

    _position.x += _velocity.x;
    _position.y += _velocity.y;

    _isGrounded = false;
    if (_velocity.y == 0)
    {
        _isGrounded = true;
    }

    _accelerataion.x = 0;
    _accelerataion.y = 0;
}

void Entity::blockCollisions(const Rect4 *blocks)
{
    Rect4 recY(_position.x, _position.y + _velocity.y, _size.x, _size.y);
    Rect4 recX(_position.x + _velocity.x, _position.y, _size.x, _size.y);

    for (int i = 0; i < BLOCKS_NUMBER; i++)
    {
        if (colisionDetec(recY, blocks[i]))
        {
            while (colisionDetec(recY, blocks[i]))
            {
                recY.y -= copysign(1, _velocity.y);
            }
            _velocity.y = 0;
        }

        if (colisionDetec(recX, blocks[i]))
        {
            while (colisionDetec(recX, blocks[i]))
            {
                recX.x -= copysign(1, _velocity.x);
            }
            _velocity.x = 0;
        }
    }
}

void Entity::input(Vector2D f)
{
    _velocity.x += f.x;
    _velocity.y += f.y;
}

void Entity::applyFriction()
{
    float u = 0.5;
    _velocity.x *= u;
}

// aux
bool colisionDetec(Rect4 s, Rect4 t)
{
    return (s.x < t.x + t.w &&
            s.x + s.w > t.x &&
            s.y < t.y + t.h &&
            s.y + s.h > t.y);
}