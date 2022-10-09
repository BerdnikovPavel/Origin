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
        name = "������������� �����������";
        print();
        if (sides_count != 3)
        {
            throw MyException("���������� ������ �� ����� 3");
        }
        if ((A + B + C) != 180)
        {
            throw MyException("����� ����� �� ����� 180");
        }
        if (C != 90)
        {
            throw MyException("���� � �� ����� 90 ��������");
        }
        std::cout << " ������" << std::endl;
    }