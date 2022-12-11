#include "Class_Figure.h"

    Figure::Figure(std::string name)
    {
        this->name = name;
    }

    Figure::Figure()
    {
        name = "Фигура";
    }

    void Figure::print() const
    {
        std::cout << name << ":" << std::endl;
    }
