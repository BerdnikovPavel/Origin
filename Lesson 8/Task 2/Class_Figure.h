#pragma once

#include <iostream>
#include "Class_MyException.h"

class Figure
{
protected:
    unsigned int sides_count;
    std::string name;
    
public:
    Figure(unsigned int sides_count);
    Figure();
    virtual void print() const;
};
