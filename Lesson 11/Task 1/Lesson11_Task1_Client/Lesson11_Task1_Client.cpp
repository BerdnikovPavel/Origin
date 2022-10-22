#include <iostream>

#include <windows.h>

#include "Greeting.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Greeting greeting;
	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << greeting.greet(name);
}