#include"Class_Parallelogram.h"

    Parallelogram::Parallelogram(unsigned int a, unsigned int b, unsigned int A, unsigned int B) : Quadrangle()
    {
        this->a = a;
        this->b = b;
        this->A = A;
        this->B = B;
    }

    Parallelogram::Parallelogram() : Parallelogram(20, 30, 30, 40)
    {
        name = "ֿאנאככוכמדנאלל";
        c = a;
        d = b;
        C = A;
        D = B;
    }