#include "Class_FastCamel.h"

FastCamel::FastCamel() : Camel()
{
	name = "Верблюд-быстроход";
	speed = 40;
	travelTimeToRest = 10;
	restTime1 = 5;
	restTime2 = 6.5;
	restTime3 = 8;
}

double FastCamel::resultCalculation(int distance) const
{
	if (distance / speed / travelTimeToRest >= 0 && distance / speed / travelTimeToRest <= 2)
	{
		return Camel::resultCalculation(distance);
	}
	else if(distance / speed / travelTimeToRest > 2 && (distance / speed) % travelTimeToRest == 0)
	{
		return ((distance / speed / travelTimeToRest - static_cast<double>(3)) * restTime3) + (distance / static_cast<double>(speed)) + restTime1 + restTime2;
	}
	else
	{
		return ((distance / speed / travelTimeToRest - static_cast<double>(2)) * restTime3) + (distance / static_cast<double>(speed)) + restTime1 + restTime2;
	}
}