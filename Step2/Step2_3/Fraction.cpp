#include "Fraction.h"

Fraction::Fraction() : Fraction(0, 1)
{
}

Fraction::Fraction(int numerator) : Fraction(numerator, 1)
{
}

Fraction::Fraction(int numerator, int denominator) :
	_n(numerator), _d(denominator)
{
	simplify();
}

Fraction::Fraction(const Fraction& fold) : Fraction(fold._n, fold._d)
{
}






