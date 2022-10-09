#include"Class_RightTriangle.h"

    RightTriangle::RightTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B, unsigned int C) :
        Triangle(sides_count, a, b, c, A, B, C)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    RightTriangle::RightTriangle() : RightTriangle(3, 10, 20, 30, 50, 40, 90)
    {
        name = "Прямоугольный треугольник";
        print();
        if (sides_count != 3)
        {
            throw MyException("Количество сторон не равно 3");
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