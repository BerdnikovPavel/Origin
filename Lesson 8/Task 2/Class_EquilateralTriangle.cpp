#include"Class_EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c,
    unsigned int A, unsigned int B, unsigned int C) : IsoscelesTriangle(sides_count, a, b, c, A, B, C)
    {
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
    }
    EquilateralTriangle::EquilateralTriangle() : EquilateralTriangle(3, 10, 10, 10, 60, 60, 60)
    {
        name = "–авносторонний треугольник";
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
            throw MyException("углы не равны");
        }
        std::cout << " создан" << std::endl;
    }