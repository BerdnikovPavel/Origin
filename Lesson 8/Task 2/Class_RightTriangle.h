#pragma once

#include "Class_Triangle.h"

class  RightTriangle : public Triangle
{
public:
    RightTriangle();
protected:
    RightTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B, unsigned int C);
};
