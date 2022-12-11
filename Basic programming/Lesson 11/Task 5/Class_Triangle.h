#pragma once

#include "Class_Figure.h"

class Triangle : public Figure
{
public:
    Triangle();
    void print() const override;
protected:
    unsigned int a, b, c, A, B, C;
    Triangle(unsigned int a, unsigned int b, unsigned int c,
        unsigned int A, unsigned int B, unsigned int C);
};
