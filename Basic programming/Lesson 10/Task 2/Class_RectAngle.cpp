#include"Class_RectAngle.h"

RectAngle::RectAngle(unsigned int a, unsigned int b) : Parallelogram()
    {
        this->a = a;
        this->b = b;
    }

RectAngle::RectAngle() : RectAngle(10, 20)
    {
        name = "Прямоугольник";
        c = a;
        d = b;
        A = B = C = D = 90;
    }

