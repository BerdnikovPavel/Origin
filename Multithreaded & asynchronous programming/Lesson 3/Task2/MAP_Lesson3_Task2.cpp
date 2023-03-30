#include <iostream>
#include <future>
#include <vector>
#include <random>

using namespace std;

template<typename It, typename Func>
void par_for_each(It begin, It end, Func*func)
{
    unsigned int length = end - begin;
    unsigned int max = 10;
    if (length < max)
    {
        for_each(begin, end, func);
    }
    else
    {
        It middle = begin + length / 2;
        future<void> res_first_half = async(par_for_each<It, Func>, begin, middle, func);
        future<void> res_second_half = async(par_for_each<It, Func>, middle, end, func);
    }
}

void mult_by_two(int x)
{
    x =  x * 2;
    cout << x << " ";
}


int main()
{
    mt19937 gen;
    uniform_int_distribution<int> dis(0, 40);
    auto rand_num([=]() mutable {return dis(gen); });
    vector<int> v(40);
    generate(v.begin(), v.end(), rand_num);
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
    par_for_each(v.begin(), v.end(), &mult_by_two);

    return 0;
}