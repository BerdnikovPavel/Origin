#include"Class_RightTriangle.h"

    RightTriangle::RightTriangle(unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B) : Triangle()
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
    }
    RightTriangle::RightTriangle() : RightTriangle(10, 20, 30, 50, 60)
    {
        name = "Прямоугольный треугольник";
        C = 90;
    }