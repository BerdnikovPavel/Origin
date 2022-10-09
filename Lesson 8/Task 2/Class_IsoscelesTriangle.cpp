#include"Class_IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c,
    unsigned int A, unsigned int B, unsigned int C) : Triangle(sides_count, a, b, c, A, B, C)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
}
IsoscelesTriangle::IsoscelesTriangle() : IsoscelesTriangle(3, 10, 20, 10, 50, 80, 50)
    {
        name = "–авнобедренный треугольник";
        print();
        if (sides_count != 3)
        {
            throw MyException("количество сторон не равно 3");
        }
        if ((A + B + C) != 180)
        {
            throw MyException("сумма углов не равна 180");
        }
        if (a != c)
        {
            throw MyException("стороны a и c не равны");
        }
        if (A != C)
        {
            throw MyException("углы A и B не равны");
        }
        std::cout << " создан" << std::endl;
    }