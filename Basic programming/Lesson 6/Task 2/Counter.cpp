#include <iostream>

#include"Counter.h"

Counter::Counter(int num)
{
	this->num = num;
}
Counter::Counter()
{
	num = 1;
}
void Counter::increment()
{
    this->num = num + 1;
}

void Counter::decrement()
{
    this->num = num - 1;
}

void Counter::print()
{
    std::cout << num << std::endl;
}

void Counter::change_num(int num)
{
    this->num = num;
}