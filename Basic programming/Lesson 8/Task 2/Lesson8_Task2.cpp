#include <iostream>

#include <windows.h>

#include "Class_Figure.h"
#include"Class_Triangle.h"
#include"Class_RightTriangle.h"
#include "Class_IsoscelesTriangle.h"
#include"Class_EquilateralTriangle.h"
#include"Class_Quadrangle.h"
#include"Class_Parallelogram.h"
#include"Class_RectAngle.h"
#include"Class_Rhombus.h"
#include"Class_Square.h"
#include"print_info.h"
#include"Class_MyException.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        Figure figure(0);
        Triangle triangle(3, 10, 20, 30, 50, 60, 70);
        RightTriangle rightTriangle(3, 10, 20, 30, 40, 50, 90);
        RightTriangle rightTriangle2(3, 10, 20, 30, 40, 40, 90);
        IsoscelesTriangle isoscelesTriangle(3, 10, 20, 10, 50, 80, 50);
        EquilateralTriangle equilateralTriangle(3, 10, 10, 10, 60, 60, 60);
        Quadrangle quadrangle(4, 10, 20, 30, 40, 50, 90, 100, 120);
        Parallelogram parallelogramm(4, 30, 20, 30, 20, 30, 150, 30, 150);
        RectAngle rectangle(4, 10, 20, 10, 20, 90, 90, 90, 90);
        Rhombus rhombus(4, 30, 30, 30, 30, 60, 120, 60, 120);
        Square square(4, 20, 20, 20, 20, 90, 90, 90, 90);
    }
    catch (const MyException& ex)
    {
        std::cout << " не был создан. Причина: " << ex.what() << std::endl;
    }
    return 0;
}
