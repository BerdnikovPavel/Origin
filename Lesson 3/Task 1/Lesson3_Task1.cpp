
#include <iostream>

class Calculator
{
public:
    double num1;
    double num2;

    double add()
    {
        return num1 + num2;
    }

    double multiply()
    {
        return num1 * num2;
    }

    double subtract_1_2()
    {
        return num1 - num2;
    }

    double subtract_2_1()
    {
        return num2 - num1;
    }

    double divide_1_2()
    {
        return num1 / num2;
    }

    double divide_2_1()
    {
        return num2 / num1;
    }

    bool set_num1(double num1)
    {
        if (num1 == 0)
        {
            std::cout << "Неверный ввод!" << std::endl;
            return false;
        }
        else
        {
            this->num1 = num1;
            return true;
        }
    }

    bool set_num2(double num2)
    {
        if (num2 == 0)
        {
            std::cout << "Неверный ввод!" << std::endl;
            return false;
        }
        else
        {
            this->num2 = num2;
            return true;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Calculator calc;
    for (; ; )
    {
        do
        {
            std::cout << "Введите num1: ";
            std::cin >> calc.num1;
        } while (calc.set_num1(calc.num1) == false);

        do
        {
            std::cout << "Введите num2: ";
            std::cin >> calc.num2;
        } while (calc.set_num2(calc.num2) == false);

        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }

    return 0;
}
