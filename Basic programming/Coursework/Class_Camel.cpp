#include "Class_Camel.h"

Camel::Camel() : Centaur()
{
	name = "Верблюд";
	speed = 10;
	travelTimeToRest = 30;
	restTime1 = 5;
	restTime2 = 8;
}

double Camel::resultCalculation(int distance) const
{
	if (distance / speed / travelTimeToRest > 1 && (distance / speed) % travelTimeToRest == 0)
	{
		return ((distance / speed / travelTimeToRest - static_cast<double>(2)) * restTime2) + (distance / static_cast<double>(speed)) + restTime1;
	}
	else if(distance / speed / travelTimeToRest > 0 && (distance / speed) % travelTimeToRest != 0)
	{
		return ((distance / speed / travelTimeToRest - static_cast<double>(1)) * restTime2) + (distance / static_cast<double>(speed)) + restTime1;
	}
	else
	{
		return distance / static_cast<double>(speed);
	}
}