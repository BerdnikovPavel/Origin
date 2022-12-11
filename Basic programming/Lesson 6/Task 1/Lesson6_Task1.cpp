#include <iostream>

#include <windows.h>

#include "math_functions.h"


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x = 0;
	int y = 0;
	int operation = 0;
	std::cout << "Введите первое число: ";
	std::cin >> x;
	std::cout << "Введите второе число: ";
	std::cin >> y;
	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> operation;
	switch (operation)
	{
	case 1:
		std::cout << x << " плюс " << y << " = " << addition(x, y) << std::endl;
		break;
	case 2: 
		std::cout << x << " минус " << y << " = " << subtraction(x, y) << std::endl;
		break;
	case 3: 
		std::cout << x << " умножить на " << y << " = " << multiplication(x, y) << std::endl;
		break;
	case 4: 
		if (y != 0)
		{
			std::cout << x << " разделить на " << y << " = " << division(x, y) << std::endl;
		}
		else
		{
			std::cout << "Ошибка! Делитель не может быть равен 0" << std::endl;
		}
		break;
	case 5:
		if (x == 0 && y == 0)
		{
			std::cout << x << " в степени " << y << " = " << "Неопределенность" << std::endl;
		}
		else if (y == 0)
		{
			std::cout << x << " в степени " << y << " = 1" << std::endl;
		}
		else 
		{
			std::cout << x << " в степени " << y << " = " << exponentiation(x, y) << std::endl;
		}
		break;
	default:
		std::cout << "Операция не обнаружена" << std::endl;
		break;
	}
	return 0;
}
