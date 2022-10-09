#pragma once
#include"Class_IsoscelesTriangle.h"

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle();
protected:
    EquilateralTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B, unsigned int C);
};