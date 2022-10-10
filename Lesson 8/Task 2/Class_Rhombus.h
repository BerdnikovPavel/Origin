#pragma once

#include"Class_Parallelogram.h"

class Rhombus : public Parallelogram
{
public:
    Rhombus();
    Rhombus(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D);
};
