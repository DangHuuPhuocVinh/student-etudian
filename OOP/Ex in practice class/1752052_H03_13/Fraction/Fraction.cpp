#include "Fraction.h"

Fraction::Fraction()
{
	this->numerator = 0;
	this->denominator = 0;
}

Fraction::Fraction(int value)
{
	this->numerator = value;
	this->denominator = 1;
}

Fraction::Fraction(int nume, int deno)
{
	this->numerator = nume;
	this->denominator = deno;
}

Fraction::Fraction(const Fraction &f)
{
	this->numerator = f.numerator;
	this->denominator = f.denominator;
}



