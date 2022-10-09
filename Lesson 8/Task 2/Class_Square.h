#pragma once

#include"Class_Rhombus.h"

class Square : public Rhombus
{
public:
    Square();
protected:
    Square(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D);
};
