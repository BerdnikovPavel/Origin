#pragma once
#include"Class_IsoscelesTriangle.h"

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    FIGURE_DLL_API EquilateralTriangle();
protected:
    FIGURE_DLL_API EquilateralTriangle(unsigned int a);
};