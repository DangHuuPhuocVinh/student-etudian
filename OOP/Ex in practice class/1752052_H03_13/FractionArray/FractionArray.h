#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Fraction
{
public:
	int nume; // nume is numerator
	int deno; // deno is denominator
};

class FractionArray
{
private:
	Fraction *a;
	int n; // n is size of array
public:
	FractionArray();
	FractionArray(int size);
	FractionArray(Fraction fnume, Fraction fdeno);
	FractionArray(const FractionArray &fa);
	~FractionArray();
};