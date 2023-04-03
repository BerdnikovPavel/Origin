#include "line.h"

Line::Line(int _x1, int _y1, int _x2, int _y2)
{
	this->x1 = _x1;
	this->x2 = _x2;
	this->y1 = _y1;
	this->y2 = _y2;
}

Line::Line(){}

double Line::get_square() const
{
	return 0;
}

double Line::get_volume() const
{
	return 0;
}

void Line::shift(int m, int n)
{
	x1 += m; y1 += n;
	x2 += m; y2 += n;
}

void Line::scaleX(int a)
{
	x1 *= a;
	x2 *= a;
}

void Line::scaleY(int d)
{
	y1 *= d;
	y2 *= d;
}

void Line::scale(int s)
{
	x1 /= s; y1 /= s;
	x2 /= s; y2 /= s;
}
