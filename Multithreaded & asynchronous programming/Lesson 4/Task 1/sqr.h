#pragma once
#include "line.h"

class Sqr : public Line
{
public:
	double get_square() const override;
	void shift(int m, int n) override;
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scale(int s) override;

protected:
	int x3 = 0, y3 = 0, x4, y4;
	Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);
};

