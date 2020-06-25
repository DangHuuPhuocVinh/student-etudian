#include "FractionArray.h"
#include<string.h>

FractionArray::FractionArray()
{
	this->a = NULL;
	this->n = 0;
}

FractionArray::FractionArray(int size)
{
	this->n = size;
	this->a = NULL;
}

FractionArray::FractionArray(Fraction fnume, Fraction fdeno)
{
	this->n = 0;
	this->a.nume = fnume;
	this->a.deno = fdeno;
}

FractionArray::FractionArray(const FractionArray &fa)
{
	this->n = fa.n;
	this->a.nume = strdup(fa.a.nume);
	this->a.deno = strdup(fa.a.deno);
}

FractionArray::~FractionArray()
{
	delete a;
	cout << "Da huy" << endl;
}