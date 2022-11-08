#pragma once

#include "Class_Centaur.h"

class Camel : public Centaur
{
protected:
	double restTime2;
public:
	Camel();
	double resultCalculation(int distance) const override;
};