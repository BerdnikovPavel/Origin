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