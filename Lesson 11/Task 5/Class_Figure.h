#pragma once

#include <iostream>

class Figure
{
protected:
    std::string name;
    Figure(std::string name);
public:
    Figure();
    virtual void print() const;
};
