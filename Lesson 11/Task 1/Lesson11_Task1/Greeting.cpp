#include "Greeting.h"

std::string Greeting::greet(std::string name)
{
	std::string g = "Здравствуйте, " + name + "!";
	return g;
}