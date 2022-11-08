#pragma once

#include "Class_Eagle.h"

class MagicCarpet : public Eagle
{
protected:
	int shortcutCoef2;
	int shortcutCoef3;
public:
	MagicCarpet();
	double resultCalculation(int distance) const override;
};
