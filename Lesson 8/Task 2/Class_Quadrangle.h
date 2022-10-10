#pragma once

#include"Class_Figure.h"

class Quadrangle : public Figure
{
public:
    Quadrangle();
    Quadrangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D);
    void print() const override;
protected:
    unsigned int a, b, c, d, A, B, C, D;
};
