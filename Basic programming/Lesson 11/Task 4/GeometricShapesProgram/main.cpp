#include <iostream>

#include <windows.h>

#include"../Lesson11_Task4/Class_Figure.h"
#include"../Lesson11_Task4/Class_Triangle.h"
#include"../Lesson11_Task4/Class_RightTriangle.h"
#include"../Lesson11_Task4/Class_IsoscelesTriangle.h"
#include"../Lesson11_Task4/Class_EquilateralTriangle.h"
#include"../Lesson11_Task4/Class_Quadrangle.h"
#include"../Lesson11_Task4/Class_Parallelogram.h"
#include"../Lesson11_Task4/Class_RectAngle.h"
#include"../Lesson11_Task4/Class_Rhombus.h"
#include"../Lesson11_Task4/Class_Square.h"
#include"../Lesson11_Task4/print_info.h"

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