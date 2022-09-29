#include "math_functions.h"

int addition(int x, int y)
{
	return x + y;
}
int subtraction(int x, int y)
{
	return x - y;
}
int multiplication(int x, int y)
{
	return x * y;
}
int division(int x, int y)
{
	return x / y;
}
int exponentiation(int x, int y)
{
	int z = x;
	for (int i = 1; i < y; ++i)
	{
		z *= x;
	}
	return z;
}