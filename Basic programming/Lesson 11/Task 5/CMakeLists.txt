cmake_minimum_required(VERSION 3.22.0)

project(Lesson11_Task5)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(Lesson11_Task5 SHARED 
  Class_Figure.h 
  Class_Figure.cpp 
  Class_Triangle.h 
  Class_Triangle.cpp
  Class_EquilateralTriangle.h 
  Class_EquilateralTriangle.cpp 
  Class_IsoscelesTriangle.h 
  Class_IsoscelesTriangle.cpp 
  Class_RightTriangle.h 
  Class_RightTriangle.cpp 
  Class_Parallelogram.h 
  Class_Parallelogram.cpp 
  Class_Quadrangle.h 
  Class_Quadrangle.cpp 
  Class_RectAngle.h 
  Class_RectAngle.cpp 
  Class_Rhombus.h 
  Class_Rhombus.cpp 
  Class_Square.h 
  Class_Square.cpp 
  print_info.h 
  print_info.cpp)
  add_executable(GeometricShapesProgram2 main.cpp)
  target_link_libraries(GeometricShapesProgram2 Lesson11_Task5)