#pragma once

#include"Class_Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    Parallelogram();
protected:
    Parallelogram(unsigned int a, unsigned int b, unsigned int A, unsigned int B);
};
