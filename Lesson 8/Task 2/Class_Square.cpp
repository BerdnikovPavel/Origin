#include"Class_Square.h"

Square::Square() : Rhombus()
{
    name = "�������";
}

Square::Square(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
    unsigned int A, unsigned int B, unsigned int C, unsigned int D) : Square() 
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
    if (a != c || b != d || c != d || a != d || a != b || c != b)
    {
        throw MyException("������� �� ����� ����� �����");
    }
    if (A != 90 || B != 90 || C != 90 || D != 90)
    {
        throw MyException("�� ��� ���� ����� 90 ��������");
    }
    std::cout << " ������" << std::endl;
    }