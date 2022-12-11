#pragma once

#include "Class_Figure.h"

class Triangle : public Figure
{
public:
    FIGURE_DLL_API Triangle();
    FIGURE_DLL_API void print() const override;
protected:
    unsigned int a, b, c, A, B, C;
    FIGURE_DLL_API Triangle(unsigned int a, unsigned int b, unsigned int c,
        unsigned int A, unsigned int B, unsigned int C);
};
