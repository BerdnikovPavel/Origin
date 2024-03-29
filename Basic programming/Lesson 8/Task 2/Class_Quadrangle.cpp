#include"Class_Quadrangle.h"

Quadrangle::Quadrangle() : Figure()
{
    name = "��������������";
}

Quadrangle::Quadrangle(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
    unsigned int A, unsigned int B, unsigned int C, unsigned int D) : Quadrangle()
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
    std::cout << " ������" << std::endl;
}

void Quadrangle::print() const
{
    std::cout << name << " (c������ " << a << ", " << b << ", " << c << ", " << d <<
        "; ���� " << A << ", " << B << ", " << C << ", " << D << ")";
}