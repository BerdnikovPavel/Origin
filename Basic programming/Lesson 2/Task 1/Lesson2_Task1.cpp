
#include <iostream>

enum class Months
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int monthNumber = 1;
	while (monthNumber != 0)
	{
		std::cout << "Введите номер месяца: ";
		std::cin >> monthNumber;
		Months month = static_cast<Months>(monthNumber);
		switch (month)
		{
		case Months::January:
			std::cout << "Январь" << std::endl;
			break;
		case Months::February:
			std::cout << "Февраль" << std::endl;
			break;
		case Months::March:
			std::cout << "Март" << std::endl;
			break;
		case Months::April:
			std::cout << "Апрель" << std::endl;
			break;
		case Months::May:
			std::cout << "Май" << std::endl;
			break;
		case Months::June:
			std::cout << "Июнь" << std::endl;
			break;
		case Months::July:
			std::cout << "Июль" << std::endl;
			break;
		case Months::August:
			std::cout << "Август" << std::endl;
			break;
		case Months::September:
			std::cout << "Сентябрь" << std::endl;
			break;
		case Months::October:
			std::cout << "Октябрь" << std::endl;
			break;
		case Months::November:
			std::cout << "Ноябрь" << std::endl;
			break;
		case Months::December:
			std::cout << "Декабрь" << std::endl;
			break;
		case static_cast<Months>(0): 
			std::cout << "До свидания";
			break;
		default:
			std::cout << "Неправильный номер!" << std::endl;
		}
	}
	return 0;
}


