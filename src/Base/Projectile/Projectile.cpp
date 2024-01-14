#include "Projectile.hpp"

Projectile::Projectile(const Entity &e)
{
    _position.x = e._position.x;
    _position.y = e._position.y;

    _isFacingLeft = e._isFacingLeft;
}

void Projectile::update(std::vector<Rect4> blocks)
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