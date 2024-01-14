#include "Entity.hpp"
#include <cmath>

Entity::Entity(float x, float y)
{
    _position.x = x;
    _position.y = y;
}

Entity::~Entity()
{
}

void Entity::update(const std::vector<Rect4> &blocks)
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

void Entity::blockCollisions(const std::vector<Rect4> &blocks)
{
    Rect4 recY(_position.x, _position.y + _velocity.y, _size.x, _size.y);
    Rect4 recX(_position.x + _velocity.x, _position.y, _size.x, _size.y);

    for (Rect4 block : blocks)
    {
        if (colisionDetec(recY, block))
        {
            while (colisionDetec(recY, block))
            {
                recY.y -= copysign(1, _velocity.y);
            }
            _velocity.y = 0;
        }

        if (colisionDetec(recX, block))
        {
            while (colisionDetec(recX, block))
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