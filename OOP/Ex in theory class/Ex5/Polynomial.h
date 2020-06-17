#pragma once
#ifndef _DaThuc_H
#define _DaThuc_H

#include<iostream>
#include<conio.h>
#include<algorithm>

class Polynomial
{
private:
	int *m_coefficient;
	int m_exponential;
public:
	
	Polynomial();
	Polynomial(const Polynomial &p);
	Polynomial(int exponential, int *coeff);
	~Polynomial();

	int GetExponential();
	int GetCoefficient(int ex);

	int Compare(const Polynomial &p);
	Polynomial CalDerivative();
	int CalValue(int x);
	Polynomial CalPrimitive();

	friend ostream& operator<<(ostream &os, const Polynomial &p);
	friend istream& operator>>(istream &is, Polynomial &p);

	Polynomial& operator+(const Polynomial &p);
	Polynomial& operator-(const Polynomial &p);
	Polynomial& operator*(const Polynomial &p);
	Polynomial& operator/(const Polynomial &p);
	Polynomial& operator=(const Polynomial &p);
	bool operator>(const Polynomial &p);
	bool operator<(const Polynomial &p);
	bool operator==(const Polynomial &p);
	bool operator!=(const Polynomial &p);
	bool operator<=(const Polynomial &p);
	bool operator>=(const Polynomial &p);
	Polynomial operator!();
	Polynomial operator~();

};

#endif 

