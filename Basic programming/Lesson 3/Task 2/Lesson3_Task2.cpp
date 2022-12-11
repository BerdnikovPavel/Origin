
#include <iostream>

class Counter
{
private:
    int num;
public:
    void increment()
    {
        this->num = num + 1;
    }

    void decrement()
    {
        this->num = num - 1;
    }

    void print()
    {
        std::cout << num << std::endl;
    }

    void change_num(int num)
    {
        this->num = num;
    }
    
    Counter(int num)
    {
        this->num = num;
    }

    Counter()
    {
        num = 1;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    Counter count;
    std::string comand1;
    std::string comand2;
    int num = 0;
    do 
    {
        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> comand1;
        if (comand1 != "да" && comand1 != "нет") {
            std::cout << "Ошибка ввода" << std::endl;
        }
    } while (comand1 != "да" && comand1 != "нет");

    if(comand1 == "да")
    {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> num;
        count.change_num(num);
    }
   
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> comand2;
        if (comand2 == "+")
        {
            count.increment();
        }
        else if (comand2 == "-")
        {
            count.decrement();
        }
        else if (comand2 == "=")
        {
            count.print();
        }
        else if (comand2 == "x")
        {
            continue;
        }
        else
        {
            std::cout << "Неверная команад" << std::endl;
        }
    } while (comand2 != "x");
    std::cout << "До свидания!" << std::endl;
    return 0;
}
