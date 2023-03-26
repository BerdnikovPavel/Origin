#include <iostream>
#include <windows.h>
#include <thread>
#include <atomic>

using namespace std;

void coming(atomic<int>& x, int max)
{
    while (x != max)
    {
        x.fetch_add(1);
        cout << "Клиентов в очереди: " << x << endl;
        this_thread::sleep_for(1s);
    }
}

void leave(atomic<int>& x)
{
    do
    {
        this_thread::sleep_for(2s);
        x.fetch_add(-1);
        cout << "Клиентов в очереди: " << x << endl;
    } while (x > 0);
}

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    atomic<int> clients_count;
    clients_count.store(0);

    thread t1(coming, ref(clients_count), 5);
    thread t2(leave, ref(clients_count));
    t1.join();
    t2.join();

    return 0;
}