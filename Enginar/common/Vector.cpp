#include "Vector.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

Vector2::Vector2()
{
    x = 0;
    y = 0;
    magnitude = 1;
}

Vector2::Vector2(float _x, float _y, float _magnitude)
{
    x = _x;
    y = _y;
    magnitude = _magnitude;
}

Vector2 Vector2::operator + (Vector2 b) 
{
    return Vector2(x+b.x, y+b.y, magnitude);
}
Vector2 Vector2::operator - (Vector2 b)
{
    return Vector2(x-b.x, y-b.y, magnitude);
}
Vector2 Vector2::operator * (float n)
{
    return Vector2(x*n, y*n, magnitude);
}
Vector2 Vector2::operator / (float n)
{
    return Vector2(x/n, y/n, magnitude);
}

void Vector2::operator += (Vector2 b)
{
    x += b.x;
    y += b.y;
}
void Vector2::operator -= (Vector2 b)
{
    x -= b.x;
    y -= b.y;
}
void Vector2::operator *= (float n)
{
    x *= n;
    y *= n;
}
void Vector2::operator /= (float n)
{
    x /= n;
    y /= n;
}

bool Vector2::operator == (Vector2 b)
{
    return x == b.x && y == b.y; // && magnitude == b.magnitude ?
}
bool Vector2::operator != (Vector2 b)
{
    return x != b.x || y != b.y; // || magnitude != b.magnitude ?
}

float Vector2::dotProduct(Vector2 b)
{
    return x*b.x + y*b.y;
}
float Vector2::getMagnitude()
{
    float sumOfSquares = x * x + y * y;
    magnitude = sqrt(sumOfSquares);
    return magnitude; 
}
float Vector2::getAngle(Vector2 b)
{
    return acosf(dotProduct(b) / (getMagnitude() * b.getMagnitude()));
}
float Vector2::crossProduct(Vector2 b)
{
    return getMagnitude() * b.getMagnitude() * sin(getAngle(b));
}
float Vector2::getDistance(Vector2 b)
{
    return getMagnitude() * b.getMagnitude() * sin(getAngle(b));
}
void Vector2::Normalize()
{
    float _magnitude = magnitude;
    *this /= getMagnitude();
    magnitude = _magnitude; // ?
}

// Vector2 Vector2::getNormalized() // anlamadim
// {
//     Vector2 b = *this->Normalize()
//     // return b;
// }

void Vector2::print()
{
    printf("x: %f\ny: %f\nmagnitude: %f", x, y, magnitude);
}