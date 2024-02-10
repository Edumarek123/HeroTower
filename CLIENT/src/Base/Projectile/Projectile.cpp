#include "Projectile.hpp"

Projectile::Projectile()
{
    _position.x = 0.0f;
    _position.y = 0.0f;
}

Projectile::Projectile(const Entity &e)
{
    _position.x = e._position.x;
    _position.y = e._position.y - 1;

    _isFacingLeft = e._isFacingLeft;
}

void Projectile::update(const Rect4 *blocks)
{
    if (!_isStatic)
    {
        input(Vector2D(_speed, 0));
        applyFriction();
    }

    this->Entity::update(blocks);

    // if (this.ticks > this.maxTicks * 0.25 && this.ticks >= this.maxTicks * 0.75) {
    // 	this.damageWindow = false;
    // }

    _ticks++;
    if (_ticks > _maxTicks)
    {
        _isActive = false;
    }
}