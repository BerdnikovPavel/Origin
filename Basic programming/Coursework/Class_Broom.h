#pragma once

#include "Class_Eagle.h"

class Broom : public Eagle
{
public:
	double resultCalculation(int distance) const override;
	Broom();
};
