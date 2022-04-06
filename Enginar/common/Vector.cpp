#include "Vector.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

vector2::vector2() : Matrix<vector2>(1,2)
{
    magnitude = 1;
    data[0][0] = 0;
    data[0][1] = 0;

}

vector2::vector2(float _x, float _y) : Matrix<vector2>(1, 2)
{
    magnitude = getMagnitude();
    data[0][0] = _x;
    data[0][1] = _y;

}

float vector2::dotProduct(vector2 b)
{
    return x*b.x + y*b.y;
}
float vector2::getMagnitude()
{
    float sumOfSquares = x * x + y * y;
    magnitude = sqrt(sumOfSquares);
    return magnitude; 
}
float vector2::getAngle(vector2 b)
{
    return acosf(dotProduct(b) / (getMagnitude() * b.getMagnitude()));
}
float vector2::crossProduct(vector2 b)
{
    return getMagnitude() * b.getMagnitude() * sin(getAngle(b));
}
float vector2::getDistance(vector2 b)
{
    return getMagnitude() * b.getMagnitude() * sin(getAngle(b));
}
void vector2::Normalize()
{
    float _magnitude = magnitude;
    *this = (*this) / getMagnitude();
    magnitude = _magnitude; // ?
}

// Vector2 Vector2::getNormalized() // anlamadim
// {
//     Vector2 b = *this->Normalize()
//     // return b;
// }

void vector2::print()
{
    printf("x: %f\ny: %f\nmagnitude: %f", x, y, magnitude);
}