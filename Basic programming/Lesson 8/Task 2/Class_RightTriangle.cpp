#include"Class_RightTriangle.h"

RightTriangle::RightTriangle() : Triangle()
{
    name = "Прямоугольный треугольник";
}

RightTriangle::RightTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c,
        unsigned int A, unsigned int B, unsigned int C) : RightTriangle()
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
    if (C != 90)
    {
        throw MyException("угол С не равен 90 градусов");
    }
    std::cout << " создан" << std::endl;
}