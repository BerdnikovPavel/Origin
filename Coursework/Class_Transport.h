#pragma once

#include <iostream>

class Transport
{
protected:
	std::string name;
	int speed;
	bool isRegistered;
	int transportType;
public:
	Transport();
	virtual double resultCalculation(int distance) const;
	std::string get_name();
	int get_transportType();
	bool get_isRegistered();
	void set_isRegistered(bool value);
};
