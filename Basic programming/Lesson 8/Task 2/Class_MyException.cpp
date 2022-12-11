#include "Class_MyException.h"

MyException::MyException(const char *msg) : domain_error(msg)
{
	
}

/*const char* MyException::what() const
{
	return "Не был создан";
}*/