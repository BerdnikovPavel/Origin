#include"Class_IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle() : Triangle()
{
    name = "–авнобедренный треугольник";

}

IsoscelesTriangle::IsoscelesTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c,
    unsigned int A, unsigned int B, unsigned int C) : IsoscelesTriangle()
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
