#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
void removeRepeats(std::vector<T> &v)
{
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
}

int main()
{
    std::vector<int> v = { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "[IN]: ";
    std::vector<int>::const_iterator i = v.cbegin();

    while (i != v.cend())
    {
        std::cout << *i << " ";
        ++i;
    }

    std::cout << std::endl << "[OUT]: ";
    removeRepeats(v);
    i = v.cbegin();

    while (i != v.cend())
    {
        std::cout << *i << " ";
        ++i;
    }

    return 0;
}
