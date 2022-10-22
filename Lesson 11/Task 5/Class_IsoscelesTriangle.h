#pragma once

#include "Class_Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle();
protected:
    IsoscelesTriangle(unsigned int a, unsigned int b, unsigned int A, unsigned int B);
};