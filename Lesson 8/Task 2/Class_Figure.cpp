#include "Class_Figure.h"

    Figure::Figure(unsigned int sides_count)
    {
        this->name = name;
        this->sides_count = sides_count;
    }

    Figure::Figure() : Figure(0)
    {
        name = "������";
        print();
        if (sides_count != 0)
        {
            throw MyException("���������� ������ �� ����� 0");
        }
        std::cout << " �������" << std::endl;
    }

    void Figure::print() const
    {
        std::cout << name << " (����������� ������ " << sides_count << ")";
    }
