#pragma once

class Vector2
{
public:
    float x, y, magnitude;
    Vector2();
    Vector2(float _x, float _y, float _magnitude);
    
    Vector2 operator + (Vector2 b);
    Vector2 operator - (Vector2 b);
    Vector2 operator * (float n);
    Vector2 operator / (float n);

    void operator += (Vector2 b);
    void operator -= (Vector2 b);
    void operator *= (float n);
    void operator /= (float n);

    bool operator == (Vector2 b);
    bool operator != (Vector2 b);

    float dotProduct(Vector2 b);
    float getMagnitude();
    float getAngle(Vector2 b);
    float crossProduct(Vector2 b);
    float getDistance(Vector2 b);
    void Normalize();
    // Vector2 getNormalized();

    void print();
};