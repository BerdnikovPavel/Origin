#pragma once

#include "Class_Camel.h"

class FastCamel : public Camel
{
protected:
	double restTime3;
public:
	FastCamel();
	double resultCalculation(int distance) const override;
};
