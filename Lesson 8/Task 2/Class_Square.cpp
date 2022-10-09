#include"Class_Square.h"

Square::Square(unsigned int sides_count, unsigned int a, unsigned int b, unsigned int c, unsigned int d,
    unsigned int A, unsigned int B, unsigned int C, unsigned int D) : Rhombus(sides_count, a, b, c, d, A, B, C, D)
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
    }

Square::Square() : Square(4, 20, 20, 20, 20, 90, 90, 90, 90)
    {
        name = "Квадрат";
        print();
        if (sides_count != 4)
        {
            throw MyException("количество сторон не равно 4");
        }
        if (a != c || b != d || c != d || a != d || a != b)
        {
            throw MyException("стороны не равны между собой");
        }
        if (A != 90 || B != 90 || C != 90 || D != 90)
        {
            throw MyException("не все углы равны 90 градусов");
        }
        std::cout << " создан" << std::endl;
    }