#pragma once

#include "Class_Triangle.h"

class  RightTriangle : public Triangle
{
public:
    FIGURE_DLL_API RightTriangle();
protected:
    FIGURE_DLL_API RightTriangle(unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B);
};
