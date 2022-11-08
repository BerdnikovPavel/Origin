#include "Class_MagicCarpet.h"

MagicCarpet::MagicCarpet() : Eagle()
{
	name = "Ковёр-самолёт";
	speed = 10;
	shortcutCoef1 = 3;
	shortcutCoef2 = 10;
	shortcutCoef3 = 5;
}

double MagicCarpet::resultCalculation(int distance) const
{
	if (distance < 1000)
	{
		return distance / static_cast<double>(speed);
	}
	else if (distance >= 1000 && distance < 5000)
	{
		return (distance - (distance / static_cast<double>(100) * shortcutCoef1)) / static_cast<double>(speed);
	}
	else if (distance >= 5000 && distance < 10000)
	{
		return (distance - (distance / static_cast<double>(100) * shortcutCoef2)) / static_cast<double>(speed);
	}
	else
	{
		return (distance - (distance / static_cast<double>(100) * shortcutCoef3)) / static_cast<double>(speed);
	}
}