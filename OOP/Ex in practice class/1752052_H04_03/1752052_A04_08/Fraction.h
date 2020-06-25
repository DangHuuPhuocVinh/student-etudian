#ifndef _Fraction_h
#define _Fraction_h

#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Fraction
{
private:
	int nume; // numerator
	int deno; // denominator
public:
	Fraction();
	Fraction(int tu, int mau);
	Fraction(const Fraction &f);
	Fraction operator+(Fraction f);
	Fraction operator+(int f);
	Fraction operator-(Fraction f);
	Fraction operator-(int f);
	Fraction operator/(Fraction f);
	Fraction operator/(int f);
	Fraction operator*(Fraction f);
	Fraction operator*(int f);
	int operator>(const Fraction &f);
	int operator<(const Fraction &f);
	int operator==(const Fraction &f);
	int operator<=(const Fraction &f);
	int operator>=(const  Fraction &f);
	int operator!=(const Fraction &f);
	Fraction& operator=(const Fraction &f);
	Fraction& operator+=(const Fraction &f);
	Fraction& operator*=(const Fraction &f);
	Fraction& operator-=(const Fraction &f);
	Fraction& operator/=(const Fraction &f);
	Fraction& operator++();
	Fraction operator++(int x);
	Fraction& operator--();
	Fraction operator--(int x);
	operator float();
	int GetNumerator();
	int GetDenominator();
	friend istream& operator >> (istream &is, Fraction &f);
	friend ostream& operator<<(ostream &os, Fraction &f);

};
#endif