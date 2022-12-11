#include <iostream>

#include <windows.h>

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Здравствуйте, " << name << std::endl;
    return 0;
}