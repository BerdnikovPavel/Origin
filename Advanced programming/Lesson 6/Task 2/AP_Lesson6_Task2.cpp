#include <iostream>
#include <list>

int main()
{
    std::list<int> list = { 1, 5, 1, 3, 4, 4 };
    std::cout << "[IN]: " << std::endl << list.size() << std::endl;
    for (const auto& element : list)
    {
        std::cout << element << std::endl;
    }

    list.unique();
    list.sort(std::greater<int>());
    std::cout << "[OUT]: " << std::endl;
    list.unique();
    for (const auto& element : list)
    {
        std::cout << element << std::endl;
    }
    return 0;
}