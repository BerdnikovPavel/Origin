cmake_minimum_required(VERSION 3.22.0)

project(Lesson11_Task3)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(Lesson11_Task2 SHARED Leaver.h Leaver.cpp)
add_executable(LeaverProgram2 main.cpp)
target_link_libraries(LeaverProgram2 Lesson11_Task2)