#include"Class_EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle() : IsoscelesTriangle()
{
    name = "�������������� �����������";
}

EquilateralTriangle::EquilateralTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c,
    unsigned int A, unsigned int B, unsigned int C) : EquilateralTriangle()
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
        throw MyException("���������� ������ �� ����� 3");
    }
    if ((A + B + C) != 180)
    {
        throw MyException("����� ����� �� ����� 180");
    }
    if (a != b || b != c || a != c)
    {
        throw MyException("������� �� �����");
    }
    if (A != 60 || B != 60 || C != 60)
    {
        throw MyException("�� ��� ���� ����� 60 ��������");
    }
    std::cout << " ������" << std::endl;
    }
