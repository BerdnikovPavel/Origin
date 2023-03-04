cmake_minimum_required(VERSION 3.20)

set(PostgreSQL_ADDITIONAL_VERSIONS "15")

project(DB_Lesson5_Task1)
add_executable(DB_Lesson5_Task1 main.cpp)

add_subdirectory(C:/Users/79127/source/libpqxx libpqxx-build)

target_compile_features(DB_Lesson5_Task1 PRIVATE cxx_std_17)

target_link_libraries(DB_Lesson5_Task1 PRIVATE pqxx)