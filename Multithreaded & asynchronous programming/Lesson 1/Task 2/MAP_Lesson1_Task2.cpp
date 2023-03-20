#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include <vector>
#include <windows.h>

using namespace std;

void sum(vector<int> v1, vector<int> v2, int core_count, int thread, vector<int> res)
{
    if (core_count == 1 || thread == 1)
    {
        for (size_t i = 0; i < v1.size()/core_count; ++i)
        {
            res[i] = v1[i] + v2[i];
        }
    }
    else if (core_count == thread)
    {
        for (size_t i = v1.size() / core_count * (thread - 1); i < v1.size(); ++i)
        {
            res[i] = v1[i] + v2[i];
        }
    } 
    else
    {
        for (size_t i = v1.size()/core_count*(thread - 1); i < v1.size() / core_count*thread; ++i)  
        {
            res[i] = v1[i] + v2[i];
        }
    }
}

double sum_p(vector<int> v1, vector<int> v2, int core_count, vector<int> res)
{
    auto start = chrono::high_resolution_clock::now();
    vector<thread> vt;
    for (int i = 1; i <= core_count; ++i)
    {
        vt.push_back(thread(sum, v1, v2, core_count, i, res));
    }
    for (auto& t : vt)
    {
        t.join();
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> t = end - start;
    return t.count();
}

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    cout << "Количество аппаратных ядер - " << thread::hardware_concurrency() << endl;
    
    mt19937 gen;
    uniform_int_distribution<int> dis(0, 1000000);
    auto rand_num([=]() mutable {return dis(gen); });
    vector<int> v1_1k(1000);
    vector<int> v2_1k(v1_1k);
    vector<int> res_1k(v1_1k);
    generate(v1_1k.begin(), v1_1k.end(), rand_num);
    generate(v2_1k.begin(), v2_1k.end(), rand_num);

    double time1k_1 = sum_p(v1_1k, v2_1k, 1, res_1k);
    double time1k_2 = sum_p(v1_1k, v2_1k, 2, res_1k);
    double time1k_4 = sum_p(v1_1k, v2_1k, 4, res_1k);
    double time1k_8 = sum_p(v1_1k, v2_1k, 8, res_1k);
    double time1k_16 = sum_p(v1_1k, v2_1k, 16, res_1k);

    vector<int> v1_10k(10000);
    vector<int> v2_10k(v1_10k);
    vector<int> res_10k(v1_10k);
    generate(v1_10k.begin(), v1_10k.end(), rand_num);
    generate(v2_10k.begin(), v2_10k.end(), rand_num);

    double time10k_1 = sum_p(v1_10k, v2_10k, 1, res_10k);
    double time10k_2 = sum_p(v1_10k, v2_10k, 2, res_10k);
    double time10k_4 = sum_p(v1_10k, v2_10k, 4, res_10k);
    double time10k_8 = sum_p(v1_10k, v2_10k, 8, res_10k);
    double time10k_16 = sum_p(v1_10k, v2_10k, 16, res_10k);

    vector<int> v1_100k(100000);
    vector<int> v2_100k(v1_100k);
    vector<int> res_100k(v1_100k);
    generate(v1_100k.begin(), v1_100k.end(), rand_num);
    generate(v2_100k.begin(), v2_100k.end(), rand_num);

    double time100k_1 = sum_p(v1_100k, v2_100k, 1, res_100k);
    double time100k_2 = sum_p(v1_100k, v2_100k, 2, res_100k);
    double time100k_4 = sum_p(v1_100k, v2_100k, 4, res_100k);
    double time100k_8 = sum_p(v1_100k, v2_100k, 8, res_100k);
    double time100k_16 = sum_p(v1_100k, v2_100k, 16, res_100k);

    vector<int> v1_1m(1000000);
    vector<int> v2_1m(v1_1m);
    vector<int> res_1m(v1_1m);
    generate(v1_1m.begin(), v1_1m.end(), rand_num);
    generate(v2_1m.begin(), v2_1m.end(), rand_num);

    double time1m_1 = sum_p(v1_1m, v2_1m, 1, res_1m);
    double time1m_2 = sum_p(v1_1m, v2_1m, 2, res_1m);
    double time1m_4 = sum_p(v1_1m, v2_1m, 4, res_1m);
    double time1m_8 = sum_p(v1_1m, v2_1m, 8, res_1m);
    double time1m_16 = sum_p(v1_1m, v2_1m, 16, res_1m);

    cout << "Размер массива" << "\t   " << v1_1k.size() << "\t\t  " << v1_10k.size()
        << "\t\t " << v1_100k.size() << "\t\t " << v1_1m.size() << std::endl;
    cout << "1 потоков" << "\t" << time1k_1 << "\t" << time10k_1 << "\t" << time100k_1 << "\t" << time1m_1 << std::endl;
    cout << "2 потоков" << "\t" << time1k_2 << "\t" << time10k_2 << "\t" << time100k_2 << "\t" << time1m_2 << std::endl;
    cout << "4 потоков" << "\t" << time1k_4 << "\t" << time10k_4 << "\t" << time100k_4 << "\t" << time1m_4 << std::endl;
    cout << "8 потоков" << "\t" << time1k_8 << "\t" << time10k_8 << "\t" << time100k_8 << "\t" << time1m_8 << std::endl;
    cout << "16 потоков" << "\t" << time1k_16 << "\t" << time10k_16 << "\t" << time100k_16 << "\t" << time1m_16 << std::endl;

    return 0;
}