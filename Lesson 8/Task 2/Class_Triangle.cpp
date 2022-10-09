#include "Class_Triangle.h"

    Triangle::Triangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c,
        unsigned int A, unsigned int B, unsigned int C) : Figure(sides_count)
    {
        this->sides_count = sides_count;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    Triangle::Triangle() : Triangle(3,10, 20, 30, 50, 60, 70)
    {
        name = "�����������";
        print();
        if (sides_count != 3)
        {
            throw MyException("���������� ������ �� ����� 3");
        }
        if ((A + B + C) != 180)
        {
            throw MyException("����� ����� �� ����� 180");
        }
        std::cout << " ������" << std::endl;
    }

    void Triangle::print() const
    {
        std::cout << name  << " (c������ " << a << ", " << b << ", " << c <<
            "; ���� " << A << ", " << B << ", " << C << ")";
    }