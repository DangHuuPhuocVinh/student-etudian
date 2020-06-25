#include "Bike.h"
#include<string.h>

void Bike::Display(Bike& a, EBike& b)
{
	a.move(2);
	b.move(2);
}

Bike::Bike(const Bike &b)
{
	this->brand = strdup(b.brand);
}

Bike& Bike::operator=(const Bike &b)
{
	if (this != &brand)
	{
		delete brand;
		this->brand = b.brand;
		this->brand = new char brand;
	}
	return *this;
}

Bike::~Bike()
{
	delete brand;
}