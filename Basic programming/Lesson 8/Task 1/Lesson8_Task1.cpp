#include <iostream>

#include <windows.h>

class BadLength : public std::exception
{
public:
    const char* what() const override { return "Вы ввели слово запретной длины!"; }
};

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length) throw BadLength();
    return str.length();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int length;
    std::string str;
    std::cout << "Введите запретную длину: ";
    std::cin >> length;
    try
    {
        do
        {
            std::cout << "Введите слово: ";
            std::cin >> str;
            std::cout << "Длина слова " << str << " равна " << function(str, length) << std::endl;
        } while (str.length() == function(str, length));
    }
    catch (const BadLength& ex) { std::cout << ex.what(); }
    std::cout << " До свидания ";
    return 0;
}
