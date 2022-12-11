
#include <iostream>
#include <locale.h>

struct BankAccount
{
    long m_accountNumber = 0;
    std::string m_ownersName;
    double m_accountBalance = 0;
};

void newBalance(BankAccount &p, double newp)
{
    p.m_accountBalance = newp;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    BankAccount p;
    double newp = 0;

    std::cout << "Введите номер счёта: ";
    std::cin >> p.m_accountNumber;
    std::cout << "Введите имя владельца: ";
    std::cin >> p.m_ownersName;
    std::cout << "Введите баланс: ";
    std::cin >> p.m_accountBalance;
    std::cout << "Введите новый баланс: ";
    std::cin >> newp;
    newBalance(p, newp);
    std::cout << "Ваш счёт: " << p.m_ownersName << ", " << p.m_accountNumber << ", " << p.m_accountBalance << std::endl;
    return 0;
}