#include <iostream>
#include <windows.h>
#include <thread>

using namespace std;

void coming(int& x, int max)
{
    while (x != max)
    {
        x += 1;
        cout << "Клиентов в очереди: " << x << endl;
        this_thread::sleep_for(1s);
    } 
}

void leave(int& x)
{
    do
    {
        this_thread::sleep_for(2s);
        x -= 1;
        cout << "Клиентов в очереди: " << x << endl;
    }while (x > 0);
}

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int clients_count = 0;

    thread t1(coming, ref(clients_count), 5);
    thread t2(leave, ref(clients_count));
    t1.join();
    t2.join();

    return 0;
}