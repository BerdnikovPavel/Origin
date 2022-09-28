#include <iostream>
#include <windows.h>

class Figure
{
protected:
    std::string name;
    unsigned int sides_count;
public:
    Figure(std::string name, unsigned int sides_count)
    {
        this->name = name;
        this->sides_count = sides_count;
    }

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
public:
    Triangle(unsigned int a, unsigned int b, unsigned int c,
        unsigned int A, unsigned int B, unsigned int C) : Triangle()
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    Triangle()
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
public:
    RightTriangle(unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B) : RightTriangle()
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
    }

    RightTriangle()
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
public:
    IsoscelesTriangle(unsigned int a, unsigned int b, unsigned int A, unsigned int B) : IsoscelesTriangle()
    {
        this->a = a;
        this->b = b;
        this->A = A;
        this->B = B;
        this->c = a;
        this->C = A;
    }

    IsoscelesTriangle()
    {
        name = "Равнобедренный треугольник";
        sides_count = 3;
    }

    bool check() override
    {
        if (Triangle::check() && c == a && C == A) { return 1; }
        else { return 0; }
    }
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle(unsigned int a) : EquilateralTriangle()
    {
        this->a = a;
        this->b = a;
        this->c = a;
    }

    EquilateralTriangle()
    {
        name = "Равносторонний треугольник";
        sides_count = 3;
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
public:
    unsigned int a, b, c, d, A, B, C, D;

    Quadrangle(unsigned int a, unsigned int b, unsigned int c, unsigned int d,
        unsigned int A, unsigned int B, unsigned int C, unsigned int D) : Quadrangle()
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

    Quadrangle()
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
public:
    Parallelogram(unsigned int a, unsigned int b, unsigned int A, unsigned int B) : Parallelogram()
    {
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }

    Parallelogram()
    {
        name = "Параллелограмм";
        sides_count = 4;
    }

    bool check() override
    {
        if (Quadrangle::check() && a == c && b == d && A == C && B == D) { return 1; }
        else { return 0; }
    }
};

class RectAngle : public Parallelogram
{
public:
    RectAngle(unsigned int a, unsigned int b) : RectAngle()
    {
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
    }

    RectAngle()
    {
        name = "Прямоугольник";
        sides_count = 4;
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
public:
    Rhombus(unsigned int a, unsigned int A, unsigned int B) : Rhombus()
    {
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }

    Rhombus()
    {
        name = "Ромб";
        sides_count = 4;
    }

    bool check() override
    {
        if (Quadrangle::check() && b == a && c == a && d == a && A == C && B == D) { return 1; }
        else { return 0; }
    }
};

class Square : public Rhombus
{
public:
    Square(unsigned int a) : Square()
    {
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
    }

    Square()
    {
        name = "Квадрат";
        sides_count = 4;
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

    Figure*figure;
    Figure fig;
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle1(10, 20, 30, 50, 60);
    RightTriangle rightTriangle2(10, 20, 30, 50, 40);
    IsoscelesTriangle isoscalesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateralTriangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram parallelogram(20, 30, 30, 40);
    RectAngle rectangle(10, 20);
    Rhombus rhombus(30, 30, 40);
    Square square(20);
    figure = &fig;
    figure->print_info();
    std::cout << std::endl;
    figure = &triangle;
    figure->print_info();
    figure = &rightTriangle1;
    figure->print_info();
    figure = &rightTriangle2;
    figure->print_info();
    figure = &isoscalesTriangle;
    figure->print_info();
    figure = &equilateralTriangle;
    figure->print_info();
    figure = &quadrangle;
    figure->print_info();
    figure = &parallelogram;
    figure->print_info();
    figure = &rectangle;
    figure->print_info();
    figure = &rhombus;
    figure->print_info();
    figure = &square;
    figure->print_info();
 
    return 0;
}
