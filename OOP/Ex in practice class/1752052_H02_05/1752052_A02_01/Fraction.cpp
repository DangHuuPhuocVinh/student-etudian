#include "Fraction.h"
#include<conio.h>

void Fraction::Input()
{
	cout << "Nhap tu: ";
	cin >> this->tu;
	do {
		cout << "Nhap mau: ";
		cin >> this->mau;
	} while (this->mau == 0);
}

void Fraction::Output()
{
	cout << "Phan so : " << this->tu << '/' << this->mau;
}

int Fraction::UCLN(Fraction a, Fraction b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return 0;
}

int Fraction::Reduce()
{
	abs(this->tu);
	abs(this->mau);

	if (this->mau != 0) {
		int c = UCLN(this->tu, this->mau); // c chua uoc chung lon nhat cua 2 phan so
		this->tu = this->tu / c;
		this->mau = this->mau / c;
	}
	return c;
}

Fraction Fraction::Add(Fraction p)
{
	Fraction sum;
	if (this->mau != 0 && p.mau != 0)
	{
		double tu = this->tu * p.mau + p.tu * (double)this->mau;
		double mau = this->mau * p.mau;
		sum = tu / mau;
	}
	return sum;
}

Fraction Fraction::Subtract(Fraction p)
{
	Fraction subtract;
	if (this->mau != 0 && p.mau != 0)
	{
		double tu = this->tu * p.mau - p2.tu * (double)this->mau;
		double mau = this->mau * p.mau;
		subtract = tu / mau;
	}
	return subtract;
}

Fraction Fraction::Multiply(Fraction p)
{
	Fraction integrated;
	if (this->mau != 0 && p.mau != 0)
	{
		int tu = this->tu * p.tu;
		int mau = this->mau * p.mau;
		integrated = tu / mau;
	}
	return integrated;
}

Fraction Fraction::Divide(Fraction p)
{
	Fraction divide;
	if (this->mau != 0 && p.mau != 0)
	{
		int tu = this->tu * p.mau;
		int mau = this->.mau * p.tu;
		divide = tu / mau;
	}
	return divide;
}

int Fraction::Compare(Fraction p)
{
	double thuong1 = this->tu / (double)this->mau;
	double thuong2 = p.tu / (double)p.mau;
	if (thuong1 > thuong2)
		return 1;
	if (thuong1 < thuong2)
		return -1;
	return 0;
}

void Fraction::Sign()
{
	if (this->mau != 0)
	{
		double thuong = tu / (double)mau;
		if (thuong > 0)
			cout << "Greater than 0";
		else if (thuong < 0)
			cout << "Less than 0";
		else
			cout "Equal to 0";
	}
}

void Fraction::Compare(Fraction f)
{
	f.UCLN();
	if (this->tu == f.tu && this->mau == f.mau)
		cout << "Hai phan so bang nhau" << endl;
	if (this->tu == f.tu && this->mau < f.mau)
		cout << "Phan so thu nhat lon hon" << endl;
	else
		cout << "Phan so thu hai lon hon" << endl;
	if (this->mau != 0 && f.mau != 0)
	{
		if (this->mau == f.mau && this->tu > f.tu)
			cout << "Phan so thu nhat lon hon" << endl;
		else
			cout << "Phan so thu hai lon hon" << endl;
	}
}

