#include <iostream>

#include <windows.h>

#include "Leaver.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Leaver leaver;
	std::string name;
	std::cout << "������� ���: ";
	std::cin >> name;
	std::cout << leaver.leave(name);
}