#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
T squaring(T&a)
{
    return a *= a;
}

template<>
std::vector<int> squaring(std::vector<int>&a)
{
    for(auto&value: a)
        {
            value *= value;
        }
    return a;
}

int main(int argc, const char** argv)
{
    auto a = 4;
    std::vector<int> v = { -1, 4, 8 };
    std::cout << "[IN]: " << a << std::endl << "[OUT]: " << squaring(a) << std::endl;
    std::cout << "[IN]: ";
    for (auto value : v)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl << "[OUT]: ";
    squaring(v);
    for (auto value : v)
    {
        std::cout << value << " ";
    }

    return 0;
}
