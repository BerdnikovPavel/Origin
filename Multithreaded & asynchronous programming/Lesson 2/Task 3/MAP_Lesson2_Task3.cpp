#include <iostream>
#include <thread>
#include <mutex>
#include <Windows.h>

using namespace std;

class Data
{
private:
 
public:
    Data(int x) : x{x}{}
    int x;
    mutex m;
};

void swap1(Data&a, Data&b)
{
    a.m.lock();
    b.m.lock();
    Data tmp(0);
    tmp.x = a.x;
    a.x = b.x;
    b.x = tmp.x;
    a.m.unlock();
    b.m.unlock();
}

void swap2(Data& a, Data& b)
{
    scoped_lock sl(a.m, b.m);
    Data tmp(0);
    tmp.x = a.x;
    a.x = b.x;
    b.x = tmp.x;
}

void swap3(Data& a, Data& b)
{
    unique_lock<mutex> ul_a(a.m);
    unique_lock<mutex> ul_b(b.m);
    Data tmp(0);
    tmp.x = a.x;
    a.x = b.x;
    b.x = tmp.x;
}

int main()
{
    Data a(5);
    Data b(7);
    cout << a.x << endl;
    cout << b.x << endl;
    swap2(a, b);
    cout << a.x << endl;
    cout << b.x << endl;
}