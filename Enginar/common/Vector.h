#ifndef VECTOR_H
#define VECTOR_H
#pragma once
#include "Matrix.h"

class vector2 : public Matrix<vector2>
{
public:
    float getX() 
    { 
        return data[0][0]; 
    }
    void setX(const float& xx) { data[0][0] = xx; }

   _declspec(property(get = getX, put = setX)) float x;


    float getY() { return data[0][1]; }
    void setY(const float& yy) { data[0][1] = yy; }
    
    _declspec(property(get = getY, put = setY)) float y;

    float magnitude;
    vector2();
    vector2(float _x, float _y);
    
    /*Vector2 operator + (Vector2 b);
    Vector2 operator - (Vector2 b);
    Vector2 operator * (float n);
    Vector2 operator / (float n);

    void operator += (Vector2 b);
    void operator -= (Vector2 b);
    void operator *= (float n);
    void operator /= (float n);

    bool operator == (Vector2 b);
    bool operator != (Vector2 b);*/

    float dotProduct(vector2 b);
    float getMagnitude();
    float getAngle(vector2 b);
    float crossProduct(vector2 b);
    float getDistance(vector2 b);
    void Normalize();
    // Vector2 getNormalized();

    void print();
};
#endif