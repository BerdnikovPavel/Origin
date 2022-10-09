#pragma once

#include "Class_Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle();
protected:
    IsoscelesTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B, unsigned int C);
};