#define _USE_MATH_DEFINES
#include <math.h>
#include "circle.h"

Circle::Circle(int _x1, int _y1, double R) : Line()
{
	this->x1 = _x1;
	this->y1 = _y1;
	this->radius = R;
}

double Circle::get_square() const
{
	return M_PI * radius * radius;
}