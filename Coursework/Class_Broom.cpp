#include "Class_Broom.h"

Broom::Broom() : Eagle()
{
	name = "Метла";
	speed = 20;
	shortcutCoef1 = 1;
}

double Broom::resultCalculation(int distance) const
{
	int newShortcutCoef = distance / 1000;
	if (newShortcutCoef > 0 && newShortcutCoef < 100)
	{
		return (distance - (distance / static_cast<double>(100) * newShortcutCoef))/static_cast<double>(speed);
	}
	else if(newShortcutCoef > 100)
	{
		newShortcutCoef = 100;
		return 0;
	}
	else
	{
		return distance / static_cast<double>(speed);
	}

}