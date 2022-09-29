#pragma once

class Counter
{
private:
    int num;
public:
    void increment();
    void decrement();
    void print();
    void change_num(int num);
    Counter(int num);
    Counter();
};