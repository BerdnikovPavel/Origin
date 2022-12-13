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
	auto x = get_variant();

	if (std::holds_alternative<int>(x))
	{
		auto a = std::get<int>(x);
		std::cout << a * 2 << std::endl;
	}
	else if (std::holds_alternative<std::string>(x))
	{
		std::string a = std::get<std::string>(x);
		std::cout << a << std::endl;
	}
	else
	{
		std::vector<int> a = std::get<std::vector<int>>(x);
		for (auto const& value : a)
		{
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
    return 0;
}