#include "cube.h"
#include<cmath>

Cube::Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, 
	int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7,
	int _y7, int _z7, int _x8, int _y8, int _z8) : Sqr(_x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4)
{
	this->x4 = _x4;
	this->y4 = _y4;
	this->z1 = _z1;
	this->z2 = _z2;
	this->z3 = _z3;
	this->z4 = _z4;
	this->x4 = _x5;
	this->y4 = _y5;
	this->z1 = _z5;
	this->x4 = _x6;
	this->y4 = _y6;
	this->z1 = _z6;
	this->x4 = _x7;
	this->y4 = _y7;
	this->z1 = _z7;
	this->x4 = _x8;
	this->y4 = _y8;
	this->z1 = _z8;

}

double Cube::get_square() const
{
	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	int c = abs(z1 - z2);
	return 2 * a * b + 2 * a * c + 2 * b * c;
}

double Cube::get_volume() const
{
	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	int c = abs(z1 - z2);
	return a * b * c;
}

void Cube::shift(int m, int n, int k)
{
	x1 += m; y1 += n; z1 += k;
	x2 += m; y2 += n; z2 += k;
	x3 += m; y3 += n; z3 += k;
	x4 += m; y4 += n; z4 += k;
	x5 += m; y5 += n; z5 += k;
	x6 += m; y6 += n; z6 += k;
	x7 += m; y7 += n; z7 += k;
	x8 += m; y8 += n; z8 += k;
}

void Cube::scaleX(int a)
{
	x1 *= a;
	x2 *= a;
	x3 *= a;
	x4 *= a;
	x5 *= a;
	x6 *= a;
	x7 *= a;
	x8 *= a;
}

void Cube::scaleY(int d)
{
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d;
	y5 *= d;
	y6 *= d;
	y7 *= d;
	y8 *= d;
}

void Cube::scaleZ(int e)
{
	z1 *= e;
	z2 *= e;
	z3 *= e;
	z4 *= e;
	z5 *= e;
	z6 *= e;
	z7 *= e;
	z8 *= e;
}

void Cube::scale(int s)
{
	x1 /= s; y1 /= s; z1 /= s;
	x2 /= s; y2 /= s; z2 /= s;
	x3 /= s; y3 /= s; z3 /= s;
	x4 /= s; y4 /= s; z4 /= s;
	x5 /= s; y5 /= s; z5 /= s;
	x6 /= s; y6 /= s; z6 /= s;
	x7 /= s; y7 /= s; z7 /= s;
	x8 /= s; y8 /= s; z8 /= s;
}
