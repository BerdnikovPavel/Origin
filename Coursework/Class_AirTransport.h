#pragma once

#include "Class_Transport.h"

class AirTransport : public Transport
{
protected:
	int shortcutCoef1;
public:
	AirTransport();
	virtual double resultCalculation(int distance) const override;
};