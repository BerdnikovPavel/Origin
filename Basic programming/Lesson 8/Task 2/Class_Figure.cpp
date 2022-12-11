#include "Class_Figure.h"

    Figure::Figure()
    {
        name = "������";
    }

    Figure::Figure(unsigned int sides_count) : Figure()
    {
        this->sides_count = sides_count;
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
