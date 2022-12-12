#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char**argv)
{
    setlocale(LC_ALL, "Russian");

    std::vector<int> v = { 4, 7, 9, 14, 12 };

    std::cout << "Входные данные: ";
    std::for_each(v.begin(), v.end(),
        [](auto value)
        {
            std::cout << value << " ";
        }
    );
    std::cout << std::endl;

    std::cout << "Выходные данные: ";
    std::for_each(v.begin(), v.end(),
        [](auto value)
        {
            if (value % 2 != 0)
            {
                value = value * 3;
                std::cout << value << " ";
            }
            else
            {
                std::cout << value << " ";
            }
        }
    );
    std::cout << std::endl;

    return 0;
}