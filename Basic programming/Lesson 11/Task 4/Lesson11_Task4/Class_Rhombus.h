#pragma once

#include"Class_Parallelogram.h"

class Rhombus : public Parallelogram
{
public:
    FIGURE_DLL_API Rhombus();
protected:
    FIGURE_DLL_API Rhombus(unsigned int a, unsigned int A, unsigned int B);
};
