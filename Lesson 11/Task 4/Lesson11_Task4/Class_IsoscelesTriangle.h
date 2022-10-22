#pragma once

#include "Class_Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    FIGURE_DLL_API IsoscelesTriangle();
protected:
    FIGURE_DLL_API IsoscelesTriangle(unsigned int a, unsigned int b, unsigned int A, unsigned int B);
};