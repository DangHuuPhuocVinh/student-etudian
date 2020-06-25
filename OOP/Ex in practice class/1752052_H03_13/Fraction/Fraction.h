#pragma once
#ifndef	_HEADER_H_
#define _HEADER_H_

#include<iostream>
#include<conio.h>

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int value);
	Fraction(int nume, int deno);
	Fraction(const Fraction &f);
	//~Fraction();
};

#endif