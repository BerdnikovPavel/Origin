#include"Class_Parallelogram.h"

    Parallelogram::Parallelogram(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D) : Quadrangle(sides_count, a, b, c, d, A, B, C, D)
    {
        this->sides_count = sides_count;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    Parallelogram::Parallelogram() : Parallelogram(4, 30, 20, 30, 20, 30, 150, 30, 150)
    {
        name = "��������������";
        print();
        if (sides_count != 4)
        {
            throw MyException("���������� ������ �� ����� 4");
        }
        if ((A + B + C + D) != 360)
        {
            throw MyException("����� ����� �� ����� 360");
        }
        if (a != c || b != d)
        {
            throw MyException("��������������� ������� �� �����");
        }
        if (A != C || B != D)
        {
            throw MyException("��������������� ���� �� �����");
        }
        std::cout << " ������" << std::endl;
    }