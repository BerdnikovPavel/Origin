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
        Figure figure;
        Triangle triangle;
        RightTriangle rightTriangle;
        IsoscelesTriangle isoscelesTriangle;
        EquilateralTriangle equilateralTriangle;
        Quadrangle quadrangle;
        Parallelogram parallelogramm;
        RectAngle rectangle;
        Rhombus rhombus;
        Square square;
    }
    catch (const MyException& ex)
    {
        std::cout << " не был создан. Причина: " << ex.what() << std::endl;
    }
    return 0;
}
