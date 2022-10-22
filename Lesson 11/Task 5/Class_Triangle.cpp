#include "Class_Triangle.h"

    Triangle::Triangle(unsigned int a, unsigned int b, unsigned int c,
        unsigned int A, unsigned int B, unsigned int C) : Figure()
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    Triangle::Triangle() : Triangle(10, 20, 30, 50, 60, 70)
    {
        name = "Треугольник";
    }

    void Triangle::print() const
    {
        std::cout << name << ":" << std::endl << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl <<
            "Углы: A=" << A << " B=" << B << " C=" << C << std::endl << std::endl;
    }