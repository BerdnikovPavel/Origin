#include <iostream>
#include <windows.h>

class Figure
{
protected:
    std::string name;
    unsigned int sides_count;

    Figure(std::string name)
    {
        this->name = name;
        this->sides_count = sides_count;
    }

public:
    Figure()
    {
        name = "Фигура";
        sides_count = 0;
    }

    virtual bool check()
    {
        if (sides_count == 0) {return 1;}
        else { return 0; }
    }

    virtual void print_info()
    {
        std::cout << name << ":" << std::endl;
        if (check())
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << sides_count << std::endl;
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
        sides_count = 3;
    }

    bool check() override
    {
        if((A + B + C) == 180 && sides_count == 3) { return 1;}
        else { return 0; }
    }
    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl <<
            "Углы: A=" << A << " B=" << B << " C=" << C << std::endl << std::endl;
    }
};

class  RightTriangle : public Triangle
{
protected:
    RightTriangle(unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B) : Triangle()
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
    }
public:
    RightTriangle() : RightTriangle(10, 20, 30, 50, 60)
    {
        name = "Прямоугольный треугольник";
        sides_count = 3;
        C = 90;
    }

    bool check() override
    {
        if (Triangle::check() && C == 90) { return 1; }
        else { return 0; }
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
        sides_count = 3;
        c = a;
        C = A;
    }

    bool check() override
    {
        if (Triangle::check() && c == a && C == A) { return 1; }
        else { return 0; }
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
        sides_count = 3;
        c = b = a;
        A = B = C = 60;
    }

    bool check() override
    {
        if ((Triangle::check()) && b == a && c == a && A == 60 && B == 60 && C == 60) { return 1; }
        else { return 0; }
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
        sides_count = 4;
    }

    bool check() override
    {
        if ((A + B + C + D) == 360 && sides_count == 4) { return 1; }
        else { return 0; }
    }

    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl <<
            "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl << std::endl;
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
        sides_count = 4;
        c = a;
        d = b;
        C = A;
        D = B;
    }

    bool check() override
    {
        if (Quadrangle::check() && a == c && b == d && A == C && B == D) { return 1; }
        else { return 0; }
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
        sides_count = 4;
        c = a;
        d = b;
        A = B = C = D = 90;
    }

    bool check() override
    {
        if (Quadrangle::check() && a == c && b == d && A == 90 && C == 90 && B == 90 && D == 90) { return 1; }
        else { return 0; }
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
        sides_count = 4;
        b = c = d = a;
        C = A;
        D = B;
    }

    bool check() override
    {
        if (Quadrangle::check() && b == a && c == a && d == a && A == C && B == D) { return 1; }
        else { return 0; }
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
        sides_count = 4;
        b = c = d = a;
        A = B = C = D = 90;
    }

    bool check() override
    {
        if (Quadrangle::check() && b == a && c == a && d == a && A == 90 && C == 90 && B == 90 && D == 90) { return 1; }
        else { return 0; }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    Triangle triangle;
    RightTriangle rightTriangle;
    Quadrangle quadrangle;
    IsoscelesTriangle isoscelesTriangle;
    EquilateralTriangle equilateralTriangle;
    Parallelogram parallelogramm;
    RectAngle rectangle;
    Rhombus rhombus;
    Square square;
    figure.print_info();
    std::cout << std::endl;
    triangle.print_info();
    rightTriangle.print_info();
    isoscelesTriangle.print_info();
    equilateralTriangle.print_info();
    quadrangle.print_info();
    rectangle.print_info();
    square.print_info();
    parallelogramm.print_info();
    rhombus.print_info();
    return 0;
}
