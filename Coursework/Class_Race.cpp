#include "Class_Race.h"

Race::Race(std::string name)
{
	this->name = name;
}

Race::Race(int racersCount, int distance)
{
	this->distance = distance;
	this->racersCount = racersCount;

}

std::string Race::get_name()
{
	return name;
}

Transport*Race::RaceResultCalculation(Transport*arr[])
{
	Transport*temp;
	for (int i = 0; i < racersCount - 1; i++)
	{
		for (int j = 0; j < racersCount - i - 1; j++)
		{
			if (arr[j]->resultCalculation(distance) > arr[j + 1]->resultCalculation(distance))
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return *arr;
};
