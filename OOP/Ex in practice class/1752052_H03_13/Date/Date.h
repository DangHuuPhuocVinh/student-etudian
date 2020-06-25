#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	Date(int year);
	Date(const Date &date);
	~Date();
};