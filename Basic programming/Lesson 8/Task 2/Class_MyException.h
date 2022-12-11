#pragma once

#include<iostream>

class MyException : public std::domain_error
{
public:
	MyException(const char *msg);
	//const char* what() const override;
protected:
	//std::string msg;
};