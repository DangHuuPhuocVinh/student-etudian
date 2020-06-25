#include "Fraction.h"

Fraction::Fraction()
{
	this->nume = 0;
	this->deno = 0;
}

Fraction::Fraction(int tu, int mau)
{
	this->nume = tu;
	this->deno = mau;
}

Fraction::Fraction(const Fraction &f)
{
	this->nume = f.nume;
	this->deno = f.deno;
}

Fraction Fraction::operator+(Fraction f)
{
	Fraction temp;
	temp.nume = this->nume * f.deno + this->deno * f.nume;
	temp.deno = this->deno * f.deno;
	return temp;
}

Fraction Fraction::operator+(int f) // f la 1 so tu nhien
{
	Fraction temp;
	temp.nume = this->nume + f;
	temp.deno = this->deno;
	return temp;
}

Fraction Fraction::operator-(Fraction f)
{
	Fraction temp;
	temp.nume = this->nume * f.deno - this->deno * f.nume;
	temp.deno = this->deno * f.deno;
	return temp;
}

Fraction Fraction::operator-(int f) // f la 1 so tu nhien
{
	Fraction temp;
	temp.nume = this->nume - f;
	temp.deno = this->deno;
	return temp;
}

Fraction Fraction::operator*(Fraction f)
{
	Fraction temp;
	temp.nume = this->nume * f.nume;
	temp.deno = this->deno * f.deno;
	return temp;
}

Fraction Fraction::operator*(int f)
{
	Fraction temp;
	temp.nume = this->nume * f;
	temp.deno = this->deno;
	return temp;
}

Fraction Fraction::operator/(Fraction f)
{
	Fraction temp;
	temp.nume = this->nume * f.deno;
	temp.deno = this->deno * f.nume;
	return temp;
}

Fraction Fraction::operator/(int f)
{
	Fraction temp;
	temp.nume = this->nume;
	temp.deno = this->deno * f;
	return temp;
}

int Fraction::operator>(const Fraction &f)
{
	float x = (float)this->nume / this->deno;
	float y = (float)f.nume / f.deno;
	if (x > y)
		return 1;
	else
		return 0;
}

int Fraction::operator<(const Fraction &f)
{
	float x = (float)this->nume / this->deno;
	float y = (float)f.nume / f.deno;
	if (x < y)
		return 1;
	else
		return 0;
}

int Fraction::operator==(const Fraction &f)
{
	float x = (float)this->nume / this->deno;
	float y = (float)f.nume / f.deno;
	if (x == y)
		return 1;
	else
		return 0;
}

int Fraction::operator<=(const Fraction &f)
{
	float x = (float)this->nume / this->deno;
	float y = (float)f.nume / f.deno;
	if (x <= y)
		return 1;
	else
		return 0;
}

int Fraction::operator>=(const Fraction &f)
{
	float x = (float)this->nume / this->deno;
	float y = (float)f.nume / f.deno;
	if (x >= y)
		return 1;
	else
		return 0;
}

int Fraction::operator!=(const Fraction &f)
{
	float x = (float)this->nume / this->deno;
	float y = (float)f.nume / f.deno;
	if (x != y)
		return 1;
	else
		return 0;
}

Fraction& Fraction::operator=(const Fraction &f)
{
	if (this != &f)
	{
		this->deno = f.deno;
		this->nume = f.nume;
	}
	return *this;
}

Fraction& Fraction::operator*=(const Fraction &f)
{
	if (this->deno == NULL)
	{
		this->nume = this->nume * f.nume;
		this->deno = f.deno * 1;
	}
	else if (f.deno == NULL)
	{
		this->nume = this->nume * f.nume;
		this->deno *= 1;
	}
	else
	{
		this->deno = this->deno * f.deno;
		this->nume = this->nume * f.nume;
	}
	return *this;
}

Fraction& Fraction::operator+=(const Fraction &f)
{
	if (this->deno == NULL)
	{
		this->deno = f.deno * 1;
		this->nume = this->nume * f.deno + f.nume;
	}
	else if (f.deno == NULL)
	{
		this->nume = this->nume + f.nume;
	}
	else
	{
		this->deno = this->deno * f.deno;
		this->nume = this->nume * f.deno + this->deno * f.nume;
	}
	return *this;
}

Fraction& Fraction::operator-=(const Fraction &f)
{
	if (this->deno == NULL)
	{
		this->deno = f.deno * 1;
		this->nume = this->nume * f.deno - f.nume;
	}
	else if (f.deno == NULL)
	{
		this->nume = this->nume - f.nume;
	}
	else
	{
		this->deno = this->deno * f.deno;
		this->nume = this->nume * f.deno - this->deno * f.nume;
	}
	return *this;
}

Fraction& Fraction::operator/=(const Fraction &f)
{
	if (this->deno == NULL)
	{
		this->nume = this->nume * f.deno;
		this->deno = 1 * f.nume;
	}
	else if (f.deno == NULL)
	{
		this->nume = this->nume * 1;
		this->deno = this->deno * f.nume;
	}
	else
	{
		this->nume = this->nume * f.deno;
		this->deno = this->deno * f.nume;
	}
}

Fraction& Fraction::operator++()
{
	this->nume = this->nume + this->deno;
	return *this;
}

Fraction Fraction::operator++(int x)
{
	Fraction temp(*this);
	this->nume = this->nume + this->deno;
	return temp;
}

Fraction& Fraction::operator--()
{
	this->nume = this->nume - this->deno;
	return *this;
}

Fraction Fraction::operator--(int x)
{
	Fraction temp(*this);
	this->nume = this->nume - this->deno;
	return temp;
}

Fraction::operator float()
{
	return (float) nume/deno;
}

int Fraction::GetNumerator()
{
	nume =  this->nume;
	return nume;
}

int Fraction::GetDenominator()
{
	deno = this->deno;
	return deno;
}

ostream& operator<<(ostream &os, const Fraction &f)
{
	os << f.GetNumerator << "/" << f.GetDenominator;
	return os;
}

istream& operator>>(istream &is, Fraction &f)
{
	is >> f.GetNumerator;
	is >> f.GetDenominator;
	return is;
}
