#include "Class_AirTransport.h"

AirTransport::AirTransport()
{
	name = "Воздушный транспорт";
	shortcutCoef1 = 1;
	transportType = 2;
}

double AirTransport::resultCalculation(int distance) const
{
	return (distance - (distance / static_cast<double>(100) * shortcutCoef1))/static_cast<double>(speed);
}