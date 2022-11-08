#include "Class_Transport.h"

Transport::Transport()
{
	name = "Транспорт";
	speed = 1;
	isRegistered = 0;
	transportType = 0;
}

double Transport::resultCalculation(int distance) const
{
	return distance / static_cast<double>(speed);
}

std::string Transport::get_name()
{
	return name;
}

bool Transport::get_isRegistered()
{
	return isRegistered;
}

void Transport::set_isRegistered(bool value)
{
	if (value != isRegistered)
	{
		isRegistered = value;
	}
}

int Transport::get_transportType()
{
	return transportType;
}


