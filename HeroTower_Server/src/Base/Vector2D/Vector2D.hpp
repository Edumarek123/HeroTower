#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

class Vector2D
{
public:
    float x = 0;
    float y = 0;

    Vector2D();
    Vector2D(float _x, float _y);

    // operators
    Vector2D &operator+=(Vector2D const &v);
};

#endif