#pragma once

#include"Class_Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    Parallelogram();
    Parallelogram(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D);
};
