#include "Class_Figure.h"

    Figure::Figure(unsigned int sides_count)
    {
        this->name = name;
        this->sides_count = sides_count;
    }

    Figure::Figure() : Figure(0)
    {
        name = "Фигура";
        print();
        if (sides_count != 0)
        {
            throw MyException("Количество сторон не равно 0");
        }
        std::cout << " создана" << std::endl;
    }

    void Figure::print() const
    {
        std::cout << name << " (Количествое сторон " << sides_count << ")";
    }
