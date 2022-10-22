#include"Class_Square.h"

Square::Square(unsigned int a) : Rhombus()
    {
        this->a = a;
    }

Square::Square() : Square(20)
    {
        name = " вадрат";
        b = c = d = a;
        A = B = C = D = 90;
    }