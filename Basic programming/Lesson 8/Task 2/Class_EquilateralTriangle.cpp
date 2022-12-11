#include"Class_EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle() : IsoscelesTriangle()
{
    name = "–авносторонний треугольник";
}

EquilateralTriangle::EquilateralTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c,
    unsigned int A, unsigned int B, unsigned int C) : EquilateralTriangle()
    {
    this->sides_count = sides_count;
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
    print();
    if (sides_count != 3)
    {
        throw MyException("количество сторон не равно 3");
    }
    if ((A + B + C) != 180)
    {
        throw MyException("сумма углов не равна 180");
    }
    if (a != b || b != c || a != c)
    {
        throw MyException("стороны не равны");
    }
    if (A != 60 || B != 60 || C != 60)
    {
        throw MyException("не все углы равны 60 градусов");
    }
    std::cout << " создан" << std::endl;
    }
