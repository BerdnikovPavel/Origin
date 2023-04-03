#pragma once
#include "circle.h"

class Cylinder : public Circle
{
public:
	double get_square() const override;
	double get_volume() const override;
protected:
	double height = 0;
	Cylinder(int _x1, int _y1, double R, double H);
};
