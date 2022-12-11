#pragma once

#include"Class_Figure.h"

class Quadrangle : public Figure
{
public:
    FIGURE_DLL_API Quadrangle();
    FIGURE_DLL_API void print() const override;
protected:
    unsigned int a, b, c, d, A, B, C, D;
    FIGURE_DLL_API Quadrangle(unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D);
};
