#include"Class_IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(unsigned int a, unsigned int b, unsigned int A, unsigned int B) : Triangle()
{
    this->a = a;
    this->b = b;
    this->A = A;
    this->B = B;
}
IsoscelesTriangle::IsoscelesTriangle() : IsoscelesTriangle(10, 20, 50, 60)
    {
        name = "�������������� �����������";
        c = a;
        C = A;
    }