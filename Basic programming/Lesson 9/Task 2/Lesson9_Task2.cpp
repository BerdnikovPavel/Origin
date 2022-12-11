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

		if (denominator_ == 0)
		{
			throw DivisionByZeroException();
		}

		int num = numerator_, denom = denominator_;
		if (num < denom)
		{
			int temp = num;
			num = denom;
			denom = temp;
		}
		while (num % denom != 0)
		{
			num = num % denom;
			int temp = num;
			num = denom;
			denom = temp;
		}
		numerator_ = numerator_ / denom;
		denominator_ = denominator_ / denom;

		if (denominator_ < 0)
		{
			denominator_ *= -1;
			numerator_ *= -1;
		}
	}

	void print()
	{
		std::cout << numerator_ << "/" << denominator_;
	}

	Fraction operator+(Fraction f1)
	{
		return Fraction(((numerator_ * f1.denominator_) + (f1.numerator_ * denominator_)), denominator_ * f1.denominator_);
	}
	Fraction operator-(Fraction f1)
	{
		return Fraction(numerator_, denominator_) + Fraction(-f1.numerator_, f1.denominator_);
	}
	Fraction operator*(Fraction f1)
	{
		return Fraction((numerator_ * f1.numerator_), denominator_ * f1.denominator_);
	}
	Fraction operator/(Fraction f1)
	{
		if (denominator_ * f1.numerator_ == 0)
		{
			throw DivisionByZeroException();
		}
		return Fraction(numerator_, denominator_) * Fraction(f1.denominator_, f1.numerator_);
	}
	Fraction& operator++()
	{
		numerator_ = numerator_ + denominator_;
		return *this;
	}
	Fraction& operator--()
	{
		numerator_ = numerator_ - denominator_;
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction& operator--(int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x1 = 0;
	int x2 = 0;
	int y1 = 1;
	int y2 = 1;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> x1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> y1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> x2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> y2;

	try
	{
		Fraction f1(x1, y1);
		Fraction f2(x2, y2);
		Fraction sum = f1 + f2;	
		f1.print(); std::cout << " + "; f2.print(); std::cout << " = "; sum.print(); std::cout << std::endl;
		Fraction sub = f1 - f2;
		f1.print(); std::cout << " - "; f2.print(); std::cout << " = "; sub.print(); std::cout << std::endl;
		Fraction mult = f1 * f2;
		f1.print(); std::cout << " * "; f2.print(); std::cout << " = "; mult.print(); std::cout << std::endl;
		Fraction div = f1 / f2;
		f1.print(); std::cout << " / "; f2.print(); std::cout << " = "; div.print(); std::cout << std::endl;
		Fraction pref_inc = ++f1 * f2;
		std::cout << "++"; f1.print(); std::cout << " * "; f2.print(); std::cout << " = "; pref_inc.print(); std::cout << std::endl;
		std::cout << "Значение дроби 1 = "; f1.print(); std::cout << std::endl;
		Fraction post_dec = f1-- * f2;
		f1.print(); std::cout << "-- * "; f2.print(); std::cout << " = "; post_dec.print(); std::cout << std::endl;
		std::cout << "Значение дроби 1 = "; f1.print(); std::cout << std::endl;
		Fraction f3(3, 7);
		Fraction f4 = f3++;
		f4.print(); std::cout << std::endl;
		f3.print();
	}
	catch (const DivisionByZeroException& ex) { std::cout << ex.what() << std::endl; }
	return 0;
}