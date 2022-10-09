#include"Class_IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c,
    unsigned int A, unsigned int B, unsigned int C) : Triangle(sides_count, a, b, c, A, B, C)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
}
IsoscelesTriangle::IsoscelesTriangle() : IsoscelesTriangle(3, 10, 20, 10, 50, 80, 50)
    {
        name = "�������������� �����������";
        print();
        if (sides_count != 3)
        {
            throw MyException("���������� ������ �� ����� 3");
        }
        if ((A + B + C) != 180)
        {
            throw MyException("����� ����� �� ����� 180");
        }
        if (a != c)
        {
            throw MyException("������� a � c �� �����");
        }
        if (A != C)
        {
            throw MyException("���� A � B �� �����");
        }
        std::cout << " ������" << std::endl;
    }