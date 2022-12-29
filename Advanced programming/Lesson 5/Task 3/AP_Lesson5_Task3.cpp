#include <iostream>
#include <vector>
#include <algorithm>

class functor
{
private:
    int sum;
    int count;

public: 
    functor(): sum{0}, count{0}{}
    void operator()(int a)
    {
        if (a % 3 == 0)
        {
            ++count;
            sum += a;
        }
    }
    int get_sum() { return sum; }
    int get_count() { return count; }
};

int main(int argc, const char** argv)
{
    std::vector<int> v = { 4, 1, 3, 6, 25, 54 };
    std::wcout << "[IN]: ";
    std::for_each(v.begin(), v.end(),
        [](auto value)
        {
            std::cout << value << " ";
        }
    );

    functor x;
    x = std::for_each(v.begin(), v.end(), x);
    std::cout << std::endl << "[OUT]: get_sum() = " << x.get_sum() << std::endl << "[OUT]: get_count() = " << x.get_count() << std::endl;
    return 0;
}