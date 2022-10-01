#include <iostream>

#include <windows.h>

#define MODE 1
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

#if !defined MODE
    #error Необходимо определить индентификатор MODE
#endif
#if MODE == 0
        std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
#define add(a, b) ((a) + (b))
    int a = 0;
    int b = 0;
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите число 1: ";
    std::cin >> a;
    std::cout << "Введите число 2: ";
    std::cin >> b;
    std::cout << "Результат сложения: " << add(a, b);
#else
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif
    return 0;
}