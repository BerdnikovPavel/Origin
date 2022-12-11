
#include <iostream>
#include <windows.h>

class Figure
{
private:
    unsigned int sides_count;
protected:
    std::string name;
    Figure(unsigned int sides_count)
    {
        this->sides_count = sides_count;
    }
public:

    Figure()
    {
        sides_count = 0;
        name = "Фигура";
    }

    unsigned int get_sides_count(){return sides_count;}
    std::string get_name() { return name; }
};

class Triangle : public Figure
{
public:
    Triangle():Figure(3)
    {
        name = "Треугольник";
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle():Figure(4)
    {
        name = "Четырёхугольник";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure f;
    Triangle t;
    Quadrangle q;
    std::cout << "Количество сторон:" << std::endl;
    std::cout << f.get_name() << ": " << f.get_sides_count() << std::endl;
    std::cout << t.get_name() << ": " << t.get_sides_count() << std::endl;
    std::cout << q.get_name() << ": " << q.get_sides_count() << std::endl;
    return 0;
}