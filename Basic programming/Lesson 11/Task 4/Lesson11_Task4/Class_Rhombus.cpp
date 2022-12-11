#include"Class_Rhombus.h"

Rhombus::Rhombus(unsigned int a, unsigned int A, unsigned int B) : Parallelogram()
    {
        this->a = a;
        this->A = A;
        this->B = B;
    }

Rhombus::Rhombus() : Rhombus(30, 30, 40)
    {
        name = "Ромб";
        b = c = d = a;
        C = A;
        D = B;
    }