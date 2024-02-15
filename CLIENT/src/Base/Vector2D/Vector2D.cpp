#include "Vector2D.hpp"

Vector2D ::Vector2D()
{
}

Vector2D ::Vector2D(float _x, float _y)
{
    x = _x;
    y = _y;
}

Vector2D &Vector2D::operator+=(Vector2D const &v)
{
    x += v.x;
    y += v.y;
    return *this;
}
