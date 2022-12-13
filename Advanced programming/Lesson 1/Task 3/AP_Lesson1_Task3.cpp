#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

int main(int argc, const char** argv)
{
    setlocale(LC_ALL, "Russian");

	double angles[] = {30, 60, 90};
	std::cout << "[Входные данные]: ";
	for (auto& value : angles)
	{
		std::cout << value << " * 3.1415926 / 180, ";
	}
	std::cout << std::endl;
	
	for (int i = 0; i < std::size(angles); ++i)
	{
		angles[i] = angles[i] * 3.1415926 / 180;
	}

	std::vector<std::function<void(double)>> functions;
	std::function < void(double) > print_sin = [] (auto angle) 
	{ 
		std::cout << "sin: " << sin(angle);
	};
	functions.push_back(print_sin);

	std::function < void(double) > print_cos = [](auto angle)
	{
		std::cout << " cos: " << cos(angle);
	};
	functions.push_back(print_cos);

	std::cout << "[Выходные данные]: " << std::endl;
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
    return 0;
}