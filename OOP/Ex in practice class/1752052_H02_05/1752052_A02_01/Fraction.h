#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Fraction
{
private:
	int tu;
	int mau;
public:
	void Input();
	void Output();
	int UCLN(Fraction a, Fraction b);
	int Reduce();
	Fraction Add(Fraction p);
	Fraction Subtract(Fraction p);
	Fraction Multiply(Fraction p);
	Fraction Divide(Fraction p);
	void Sign();
	void Compare(Fraction p);
};