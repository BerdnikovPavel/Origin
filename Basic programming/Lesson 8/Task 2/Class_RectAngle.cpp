#include"Class_RectAngle.h"

RectAngle::RectAngle() : Parallelogram()
{
    name = "�������������";
}


RectAngle::RectAngle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
    unsigned int A, unsigned int B, unsigned int C, unsigned int D) : RectAngle()
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
    if (A != 90 || B != 90 || C != 90 || D != 90)
    {
        throw MyException("�� ��� ���� ����� 90 ��������");
    }
    if (a != c || b != d)
    {
        throw MyException("��������������� ������� �� �����");
    }
    std::cout << " ������" << std::endl;
    }


