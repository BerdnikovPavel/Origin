#pragma once

#include "Class_Centaur.h"
#include "Class_Camel.h"
#include "Class_AllterrainBoots.h"
#include "Class_FastCamel.h"
#include "Class_MagicCarpet.h"
#include "Class_Eagle.h"
#include "Class_Broom.h"
#include "Class_Transport.h"

class Race
{
protected:
	std::string name;
	int distance;
	int racersCount;
public:
	Race(std::string name);
	Race(int racersCount, int distance);
	std::string get_name();
	Transport*RaceResultCalculation(Transport*arr[]);
};