#pragma once
#ifndef _LECTURER_H
#define _LECTURER_H

#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class Lecturer
{
protected:
	int DayInClass;
	float rate;
	double Salary;
	double NumberOfClasses;
private:
	int ID;
	string name;
	string telephone;
	string address;
public:
	virtual void GetInfo() = 0;
	virtual void Output() = 0;
	virtual void Money() = 0;
	//virtual void Total() {};
};

class TeachingAssistant : public Lecturer
{
public:
	void GetInfo();
	void Output();
	void Money();
};

class Contract_base : public Lecturer
{
public:
	void GetInfo();
	void Output();
	void Money();
};

class FullTime : public Lecturer
{
public:
	void GetInfo();
	void Output();
	void Money();
};


#endif // !_LECTURER_H
