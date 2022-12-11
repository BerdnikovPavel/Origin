#include "Class_Triangle.h"

    Triangle::Triangle() : Figure()
    {
        name = "Треугольник";
    }

    Triangle::Triangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c,
        unsigned int A, unsigned int B, unsigned int C)  : Triangle()
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
            throw MyException("Количество сторон не равно 3");
        }
        if ((A + B + C) != 180)
        {
            throw MyException("сумма углов не равна 180");
        }
        std::cout << " создан" << std::endl;
    }

    void Triangle::print() const
    {
        std::cout << name  << " (cтороны " << a << ", " << b << ", " << c <<
            "; углы " << A << ", " << B << ", " << C << ")";
    }