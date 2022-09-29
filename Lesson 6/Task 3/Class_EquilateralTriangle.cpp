#include"Class_EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(unsigned int a) : IsoscelesTriangle()
    {
        this->a = a;
    }
    EquilateralTriangle::EquilateralTriangle() : EquilateralTriangle(30)
    {
        name = "Равносторонний треугольник";
        c = b = a;
        A = B = C = 60;
    }