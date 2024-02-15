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

void Projectile::copy(const Projectile &p)
{
    this->Entity::copy(p);

    _isActive = p._isActive;
    _isStatic = p._isStatic;

    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        _hittedIDs[i] = p._hittedIDs[i];
    }

    _ticks = p._ticks;
    _maxTicks = p._maxTicks;
    _damage = p._damage;
    _damageWindow = p._damageWindow;
    _speed = p._speed;
}

void Projectile::reset(const Entity &e)
{
    _position.x = e._position.x;
    _position.y = e._position.y - 1;

    _isFacingLeft = e._isFacingLeft;

    _ticks = 0;
    _isActive = true;
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