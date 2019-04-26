#pragma once
#include <ostream>
#include <istream>
#include <sstream>
#include <numeric>

using std::ostream;
using std::istream;

class Fraction
{
public:
	Fraction();
	Fraction(int numerator);
	Fraction(int numerator, int denominator);
	Fraction(const Fraction& fold);
	~Fraction() = default;

	/* Overloaded operators */
	inline Fraction operator+(const Fraction& rhs) const;
	inline Fraction operator-(const Fraction& rhs) const;
	inline Fraction operator*(const Fraction& rhs) const;
	inline Fraction operator/(const Fraction& rhs) const;

	/* Friend cause << needs to access _n and _d */
	friend ostream& operator<<(ostream& os, const Fraction& f);
	friend istream& operator>>(istream& is, Fraction& f);

private:
	int _n; /* numerator */
	int _d; /* denominator */

	/* reduce and move sign to nominator */
	inline void simplify();
};

inline ostream& operator<<(ostream& os, const Fraction& f)
{
	if (f._d == 1)
	{
		os << f._n;
	}
	else
	{
		os << f._n << "/" << f._d;
	}
	return os;
}


inline istream& operator>>(istream& is, Fraction& f)
{
	char input[100];
	char nominator[100];
	char denominator[100];

	/* Read n/d */
	is >> input;

	/* Split into nominator and denominator */
	std::stringstream ss(input);
	ss.getline(nominator, 100, '/');
	ss.getline(denominator, 100);

	/* Translate to integer */
	f._n = strtol(nominator, NULL, 10);
	f._d = strtol(denominator, NULL, 10);

	return is;
}


Fraction Fraction::operator+(const Fraction& rhs) const
{
	int n3 = _n * rhs._d + rhs._n * _d;
	int d3 = _d * rhs._d;
	return Fraction(n3, d3);
}

inline Fraction operator+(const int& val, const Fraction& rhs)
{
	return Fraction(val) + rhs;
}


Fraction Fraction::operator-(const Fraction& rhs) const
{
	int n3 = _n * rhs._d - rhs._n * _d;
	int d3 = _d * rhs._d;
	return Fraction(n3, d3);
}

inline Fraction operator-(const int& val, const Fraction& rhs)
{
	return Fraction(val) - rhs;
}


Fraction Fraction::operator*(const Fraction& rhs) const
{
	int n3 = _n * rhs._n;
	int d3 = _d * rhs._d;
	return Fraction(n3, d3);
}

inline Fraction operator*(const int& val, const Fraction& rhs)
{
	return Fraction(val) * rhs;
}


Fraction Fraction::operator/(const Fraction& rhs) const
{
	int n3 = _n * rhs._d;
	int d3 = _d * rhs._n;
	return Fraction(n3, d3);
}


inline Fraction operator/(const int& val, const Fraction& rhs)
{
	return Fraction(val) / rhs;
}

void Fraction::simplify()
{
	//Invalid fraction
	if (_d == 0)
	{
		return;
	}

	if (_n == 0)
	{
		_d = 1;
		return;
	}

	const int v = std::gcd(_n, _d);

	/* reduce */
	int n = abs(_n) / v;
	int d = abs(_d) / v;

	/* give correct sign */
	if ((_n * _d) < 0)
		n = -n;

	_n = n;
	_d = d;
}


