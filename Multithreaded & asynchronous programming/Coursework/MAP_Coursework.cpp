#include <iostream>
#include <thread>
#include <chrono>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

template<class T>
class safe_queue
{
private:
    mutex m;
    condition_variable cv;
public:
    queue <T> q;

    safe_queue() : q(), m(), cv() {}

    ~safe_queue() {}

    void push(T f)
    {
        lock_guard<mutex> lock(m);
        q.push(f);
        cv.notify_one();
    }

    T pop()
    {
        unique_lock<mutex> lock(m);
        while (q.empty())
        {
            cv.wait(lock);
        }
        T element = q.front();
        q.pop();
        return element;
    }
};

class thread_pool
{   
private:
    vector<thread> threads;
    safe_queue<function<void()>> sq;
    atomic<bool> done = false;
public: 
    thread_pool()
    {
        const int thread_count = thread::hardware_concurrency();
        for (int i = 0; i < thread_count; ++i)
        {
            threads.push_back(thread(&thread_pool::work, this));
        }
    }

    ~thread_pool()
    {
        done = true;
        for (auto& t : threads)
        {
            t.join();
        }
    }

    void work()
    {
        while (!done)
        {
            if (!sq.q.empty())
            {
                function<void()> task;
                task = sq.pop();
                task();
            }
            else
            {
                this_thread::yield();
            }
        }
    }

    void submit(function<void()> f)
    {
        sq.push(f);
    }
};

void function1() { this_thread::sleep_for(100ms);  cout << "I am function1" << endl; }
void function2() { this_thread::sleep_for(200ms);  cout << "I am function2" << endl; }
void function3() { this_thread::sleep_for(300ms);  cout << "I am function3" << endl; }


int main()
{
    thread_pool tp;

    tp.submit(function1);
    tp.submit(function2);
    this_thread::sleep_for(1s);
    tp.submit(function3);
    tp.submit(function1);
    this_thread::sleep_for(1s);
    tp.submit(function2);
    tp.submit(function3);
    return 0;
}