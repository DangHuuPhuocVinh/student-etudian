#pragma once
#ifndef _BIKE_H
#define _BIKE_H

#include"iostream"
#include<conio.h>

class Bike
{
private:
	char *brand;
public:
	virtual void move(int t1)
	{
		cout << brand << ":" << t1*t2 << " ";
	}
	Bike(const Bike &b);
	Bike& operator=(const Bike &b);
	~Bike();
	void Display(Bike& a, EBike& b);
};

class EBike : public Bike
{
	public: void move(int t2)
	{
		Bike::move(t2 * 2);
	}
};
#endif 

