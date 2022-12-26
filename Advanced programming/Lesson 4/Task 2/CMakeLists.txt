cmake_minimum_required(VERSION 3.20)
project(MyUnitTests2)
add_executable(MyUnitTests2 main.cpp)

add_subdirectory(C:/Users/79127/source/repos/NetoTesting/Catch2 Catch2-build)
target_link_libraries(MyUnitTests2 PRIVATE Catch2::Catch2)