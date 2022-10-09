#include"Class_Rhombus.h"

Rhombus::Rhombus(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
    unsigned int A, unsigned int B, unsigned int C, unsigned int D) : Parallelogram(sides_count, a, b, c, d, A, B, C, D)
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

Rhombus::Rhombus() : Rhombus(4, 30, 30, 30, 30, 60, 120, 60, 120)
    {
        name = "����";
        print();
        if (sides_count != 4)
        {
            throw MyException("���������� ������ �� ����� 4");
        }
        if ((A + B + C + D) != 360)
        {
            throw MyException("����� ����� �� ����� 360");
        }
        if (a != c || b != d || c != d || a != d || a != b)
        {
            throw MyException("������� �� ����� ����� �����");
        }
        if (A != C || B != D)
        {
            throw MyException("��������������� ���� �� �����");
        }
        std::cout << " ������" << std::endl;
    }