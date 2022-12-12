#include <iostream>
#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main(int argc, const char** argv)
{
	if (std::holds_alternative<int>(get_variant()))
	{
		auto x = std::get<int>(get_variant());
		std::cout << x * 2 << std::endl;
	}
	else if (std::holds_alternative<std::string>(get_variant()))
	{
		auto x = std::get<std::string>(get_variant());
		std::cout << x << std::endl;
	}
	else
	{
		auto x = std::get<std::vector<int>>(get_variant());
		for (auto const& value : x)
		{
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
    return 0;
}