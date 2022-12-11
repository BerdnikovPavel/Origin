#pragma once

#include"Class_Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    FIGURE_DLL_API Parallelogram();
protected:
    FIGURE_DLL_API Parallelogram(unsigned int a, unsigned int b, unsigned int A, unsigned int B);
};
