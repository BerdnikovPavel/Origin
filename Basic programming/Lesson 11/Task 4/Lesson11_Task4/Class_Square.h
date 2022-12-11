#pragma once

#include"Class_Rhombus.h"

class Square : public Rhombus
{
public:
    FIGURE_DLL_API Square();
protected:
    FIGURE_DLL_API Square(unsigned int a);
};
