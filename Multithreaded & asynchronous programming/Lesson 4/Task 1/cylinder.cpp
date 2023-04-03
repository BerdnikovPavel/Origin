#define _USE_MATH_DEFINES
#include <math.h>
#include "cylinder.h"

Cylinder::Cylinder(int _x1, int _y1, double R, double H) : Circle(_x1, _y1, R)
{
	this->height = H;
}

double Cylinder::get_square() const
{
	return M_PI * radius * radius + 2 * radius * height;
}

double Cylinder::get_volume() const
{
	return M_PI * radius * radius * height;
}