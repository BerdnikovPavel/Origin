#pragma once

#include"Class_Parallelogram.h"

class RectAngle : public Parallelogram
{
public:
    FIGURE_DLL_API RectAngle();
protected:
    FIGURE_DLL_API RectAngle(unsigned int a, unsigned int b);
};
