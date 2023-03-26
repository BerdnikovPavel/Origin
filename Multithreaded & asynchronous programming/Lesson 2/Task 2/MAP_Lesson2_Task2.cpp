#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <Windows.h>

using namespace std;

class consol_parameter
{
public:
    static void SetColor(int text, int background)
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    static void SetPosition(int x, int y)
    {
        COORD point;
        point.X = x;
        point.Y = y;
        SetConsoleCursorPosition(hStdOut, point);
    }
private:
    static HANDLE hStdOut;
};
HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::string m_name;
    std::chrono::time_point<clock_t> m_beg;
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }

public:
    Timer() : m_beg(clock_t::now()) { }
    Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }

    void start(std::string name) {
        m_name = name;
        m_beg = clock_t::now();
    }
    void print() const {
        std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
    }
};

mutex m1;

void calculation(int calc_length, int thread_number)
{
    unique_lock<mutex>l(m1);
    Timer t;
    int x = 0;
    int time = 1 + thread_number;
    consol_parameter c;
    c.SetPosition(x, thread_number);
    cout << thread_number + 1;
    while (x != calc_length)
    {
        l.unlock();
        this_thread::sleep_for(std::chrono::seconds(time));
        l.lock();
        c.SetPosition(x + 1, thread_number);
        cout << "|";
        ++x;
        this_thread::sleep_for(300ms);
    }
    c.SetPosition(x + 1, thread_number);
    t.print();
}

int main()
{
    int thread_count = 3;
    int calc_length = 10;
    vector<thread> threads;
    for (int i = 0; i < thread_count; ++i)
    {
        threads.push_back(thread(calculation, calc_length, i));
    }
    for (auto& t : threads)
    {
        t.join();
    }
    return 0;
}
