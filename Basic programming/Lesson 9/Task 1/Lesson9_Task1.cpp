#include <iostream>

#include <windows.h>

class DivisionByZeroException : public std::exception
{
public:
	const char* what() const override { return "Делитель не может быть равен 0"; }
};

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	double div() 
	{
		if(denominator_ == 0)
		{
			throw DivisionByZeroException();
		}
		return numerator_ / denominator_; 
	}
	bool operator==(Fraction f1) { return div() == f1.div(); }
	bool operator!=(Fraction f1) { return !(*this == f1); }
	bool operator>(Fraction f1) { return div() > f1.div(); }
	bool operator<(Fraction f1) { return f1 > *this; }
	bool operator>=(Fraction f1) { return !(*this < f1); }
	bool operator<=(Fraction f1) { return !(*this > f1); }
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		Fraction f1(4, 3);
		Fraction f2(6, 11);

		std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
		std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
		std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
		std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
		std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
		std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	}
	catch (const DivisionByZeroException& ex) { std::cout << ex.what() << std::endl; }
	return 0;
}