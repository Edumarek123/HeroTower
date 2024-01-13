#include "Entity.hpp"

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
    // _accelerataion.y += 0.15;
    _velocity += _accelerataion;

    if (_velocity.x > _maxVelocity)
    {
        _velocity.x = _maxVelocity;
    }

    if (_velocity.x < -_maxVelocity)
    {
        _velocity.x = -_maxVelocity;
    }

    // _velocity.x = (int)_velocity.x;
    // _velocity.y = (int)_velocity.y;

    _isGrounded = false;
    if (_velocity.y == 0)
    {
        _isGrounded = true;
    }

    _position.x += _velocity.x;
    _position.y += _velocity.y;

    _accelerataion.x = 0;
    _accelerataion.y = 0;

    // blockCollisions(blocks);
}

void Entity::blockCollisions(const std::vector<Rect4> &blocks)
{
    // Rect4 sizeB = (w : this.sWidth / blocks.length, h : this.sHeight / blocks[0].length} let recY = {x : this.position.x, y : this.position.y + this.velocity.y, w : this.size.w, h : this.size.h};
    // Rect4 recX = {x : this.position.x + this.velocity.x, y : this.position.y, w : this.size.w, h : this.size.h};

    // for (let i = 0; i < blocks.length; i++)
    // {
    //     for (let j = 0; j < blocks[i].length; j++)
    //     {
    //         if (blocks[i][j])
    //         {
    //             let rectB = {x : i * sizeB.w, y : j * sizeB.h, w : sizeB.w, h : sizeB.h};

    //             if (colisionDetec(recY, rectB))
    //             {
    //                 while (colisionDetec(recY, rectB))
    //                 {
    //                     recY.y -= Math.sign(this.velocity.y);
    //                 }
    //                 this.velocity.y = 0;
    //             }

    //             if (this.colisionDetec(recX, rectB))
    //             {
    //                 while (this.colisionDetec(recY, rectB))
    //                 {
    //                     recY.x -= Math.sign(this.velocity.x);
    //                 }
    //                 this.velocity.x = 0;
    //             }
    //         }
    //     }
    // }
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