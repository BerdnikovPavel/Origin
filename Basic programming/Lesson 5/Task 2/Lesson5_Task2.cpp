
#include <iostream>
#include <windows.h>

class Figure
{
protected:
    std::string name;

    Figure(std::string name)
    {
        this->name = name;
    }

public:
    Figure()
    {
        name = "Фигура";
    }

    virtual void print()
    {
        std::cout << name << ":" << std::endl;
    }
};

class Triangle : public Figure
{
protected:
    unsigned int a, b, c, A, B, C;

    Triangle(unsigned int a, unsigned int b, unsigned int c,
        unsigned int A, unsigned int B, unsigned int C) : Figure()
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

public:
    Triangle() : Triangle(10, 20, 30, 50, 60, 70)
    {
        name = "Треугольник";
    }

    unsigned int get_a() { return a; }
    unsigned int get_b() { return b; }
    unsigned int get_c() { return c; }
    unsigned int get_A() { return A; }
    unsigned int get_B() { return B; }
    unsigned int get_C() { return C; }

    void print() override
    {
        std::cout << name << ":" << std::endl << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl <<
            "Углы: A=" << A << " B=" << B << " C=" << C << std::endl << std::endl;
    }
};

class  RightTriangle : public Triangle
{
protected:
    RightTriangle(unsigned int a, unsigned int b, unsigned int c,  unsigned int A, unsigned int B): Triangle()
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
    }
public:
    RightTriangle(): RightTriangle(10, 20, 30, 50, 60)
    {
        name = "Прямоугольный треугольник";
        C = 90;
    }
};

class IsoscelesTriangle : public Triangle
{
protected:
    IsoscelesTriangle(unsigned int a, unsigned int b, unsigned int A, unsigned int B) : Triangle()
    {
        this->a = a;
        this->b = b;
        this->A = A;
        this->B = B;
    }
public:
    IsoscelesTriangle() : IsoscelesTriangle(10, 20, 50, 60)
    {
        name = "Равнобедренный треугольник";
        c = a;
        C = A;
    }

   void print() override
    {
        std::cout << name << ":" << std::endl << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_a() << std::endl <<
            "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_A() << std::endl << std::endl;
    }
};

class EquilateralTriangle : public IsoscelesTriangle
{
protected:
    EquilateralTriangle(unsigned int a) : IsoscelesTriangle()
    {
        this->a = a;
    }
public:
    EquilateralTriangle() : EquilateralTriangle(30)
    {
        name = "Равносторонний треугольник";
        c = b = a;
        A = B = C = 60;
    }

    void print() override
    {
        std::cout << name << ":" << std::endl << "Стороны: a=" << get_a() << " b=" << get_a() << " c=" << get_a() << std::endl <<
            "Углы: A=" << get_A() << " B=" << get_A() << " C=" << get_A() << std::endl << std::endl;
    }
};

class Quadrangle : public Figure
{
protected:
    unsigned int a, b, c, d, A, B, C, D;

    Quadrangle(unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D) : Figure()
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

public:
    Quadrangle() : Quadrangle(10, 20, 30, 40, 50, 60, 70, 80)
    {
        name = "Четырёхугольник";
    }

    unsigned int get_a(){return a;}
    unsigned int get_b(){return b;}
    unsigned int get_c(){return c;}
    unsigned int get_d(){return d;}
    unsigned int get_A(){return A;}
    unsigned int get_B(){return B;}
    unsigned int get_C(){return C;}
    unsigned int get_D(){return D;}

    void print() override
    {
        std::cout << name << ":" << std::endl << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl <<
            "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl << std::endl;
    }
};

class Parallelogram : public Quadrangle
{
protected:
    Parallelogram(unsigned int a, unsigned int b, unsigned int A, unsigned int B) : Quadrangle()
    {
        this->a = a;
        this->b = b;
        this->A = A;
        this->B = B;
    }
public:
    Parallelogram() : Parallelogram(20, 30, 30, 40)
    {
        name = "Параллелограмм";
        c = a;
        d = b;
        C = A;
        D = B;
    }

    void print() override
    {
        std::cout << name << ":" << std::endl << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_a() << " d=" << get_b() << std::endl <<
            "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_A() << " D=" << get_B() << std::endl << std::endl;
    }
};

class RectAngle : public Parallelogram
{
protected:
    RectAngle(unsigned int a, unsigned int b) : Parallelogram()
    {
        this->a = a;
        this->b = b;
    }
public:
    RectAngle() : RectAngle(10, 20)
    {
        name = "Прямоугольник";
        c = a;
        d = b;
        A = B = C = D = 90;
    }

    void print() override
    {
       std::cout << name << ":" << std::endl << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_a() << " d=" << get_b() << std::endl <<
           "Углы: A=" << get_A() << " B=" << get_A() << " C=" << get_A() << " D=" << get_A() << std::endl << std::endl;
    }
};

class Rhombus : public Parallelogram
{
protected:
    Rhombus(unsigned int a, unsigned int A, unsigned int B) : Parallelogram()
    {
        this->a = a;
        this->A = A;
        this->B = B;
    }
public:
    Rhombus() : Rhombus(30, 30, 40)
    {
        name = "Ромб";
        b = c = d = a;
        C = A;
        D = B;
    }

    void print() override
    {
       std::cout << name << ":" << std::endl << "Стороны: a=" << get_a() << " b=" << get_a() << " c=" << get_a() << " d=" << get_a() << std::endl <<
           "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_A() << " D=" << get_B() << std::endl << std::endl;
    }
};

class Square : public Rhombus
{
protected:
    Square(unsigned int a) : Rhombus()
    {
        this->a = a;
    }
public:
    Square() : Square(20)
    {
        name = "Квадрат";
        b = c = d = a;
        A = B = C = D = 90;
    }

    void print() override
    {
        std::cout << name << ":" << std::endl << "Стороны: a=" << get_a() << " b=" << get_a() << " c=" << get_a() << " d=" << get_a() << std::endl <<
            "Углы: A=" << get_A() << " B=" << get_A() << " C=" << get_A() << " D=" << get_A() << std::endl << std::endl;
    }
};

void print_info(Figure*figure)
{
    figure->print();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle triangle;
    RightTriangle rightTriangle;
    Quadrangle quadrangle;
    IsoscelesTriangle isoscelesTriangle;
    EquilateralTriangle equilateralTriangle;
    Parallelogram parallelogramm;
    RectAngle rectangle;
    Rhombus rhombus;
    Square square;
    print_info(&triangle);
    print_info(&rightTriangle);
    print_info(&isoscelesTriangle);
    print_info(&equilateralTriangle);
    print_info(&quadrangle);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogramm);
    print_info(&rhombus);
    return 0;
}
