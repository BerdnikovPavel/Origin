#pragma once
#include "sqr.h"

class Cube : public Sqr
{
public:
	double get_square() const override;
	double get_volume() const override;
	void shift(int m, int n, int k);
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scaleZ(int e);
	void scale(int s) override;
protected:
	int z1 = 0, z2 = 0, z3 = 0, x4 = 0, y4 = 0, z4 = 0, x5 = 0, y5 = 0, z5 = 0, x6 = 0, y6 = 0, z6 = 0, 
		x7 = 0, y7 = 0, z7 = 0, x8 = 0, y8 = 0, z8 = 0;
	Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4,
		int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
};