#include <iostream>
#include <thread>
#include <mutex>

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
    lock(a.m, b.m);
    lock_guard<mutex> lg_b(a.m, adopt_lock);
    lock_guard<mutex> lg_a(b.m, adopt_lock);
    Data tmp(0);
    tmp.x = a.x;
    a.x = b.x;
    b.x = tmp.x;
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
    unique_lock<mutex> ul_a(a.m, defer_lock);
    unique_lock<mutex> ul_b(b.m, defer_lock);
    lock(a.m, b.m);
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
    swap1(a, b);
    cout << a.x << endl;
    cout << b.x << endl;
}