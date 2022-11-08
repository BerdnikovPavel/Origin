#include "Class_GroundTransport.h"

GroundTransport::GroundTransport() : Transport()
{
	name = "Наземный транспорт";
	transportType = 1;
	travelTimeToRest = 1;
	restTime1 = 0;
}

double GroundTransport::resultCalculation(int distance) const
{
	if ((distance / speed) % travelTimeToRest == 0)
	{
		return ((distance / speed / travelTimeToRest - static_cast<double>(1))* restTime1) + (distance / static_cast<double>(speed));
	}
	else
	{
		return (distance / speed / travelTimeToRest * restTime1) + (distance / static_cast<double>(speed));
	}	
}