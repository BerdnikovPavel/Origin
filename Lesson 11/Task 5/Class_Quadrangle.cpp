#include"Class_Quadrangle.h"

    Quadrangle::Quadrangle(unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D) : Figure()
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    Quadrangle::Quadrangle() : Quadrangle(10, 20, 30, 40, 50, 60, 70, 80)
    {
        name = "Четырёхугольник";
    }

    void Quadrangle::print() const
    {
        std::cout << name << ":" << std::endl << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl <<
            "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl << std::endl;
    }