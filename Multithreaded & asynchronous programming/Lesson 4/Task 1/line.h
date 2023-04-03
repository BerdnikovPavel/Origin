#pragma once

class Line
{
public:
	virtual double get_square() const;
	virtual double get_volume() const;
	virtual void shift(int m, int n);
	virtual void scaleX(int a);
	virtual void scaleY(int d);
	virtual void scale(int s);

	Line();
protected:
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	Line(int _x1, int _y1, int _x2, int _y2);
};
