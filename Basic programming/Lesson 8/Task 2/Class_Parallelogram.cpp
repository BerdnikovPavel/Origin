#include"Class_Parallelogram.h"

Parallelogram::Parallelogram() : Quadrangle()
{
    name = "��������������";
}

Parallelogram::Parallelogram(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D) : Parallelogram()
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