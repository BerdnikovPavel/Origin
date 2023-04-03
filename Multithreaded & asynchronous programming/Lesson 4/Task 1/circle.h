#pragma once
#include "line.h"

class Circle : public Line
{
public:
	double get_square() const override;
protected:
	double radius = 0;
	Circle(int _x1, int _y1, double R);
};
