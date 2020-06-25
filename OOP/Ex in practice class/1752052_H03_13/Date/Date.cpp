#include "Date.h"

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = day;
	this->year = year;
}

Date::Date(int year)
{
	this->day = 1;
	this->month = 1;
	this->year = year;
}

Date::Date(const Date &date)
{
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}

Date::~Date()
{
	cout << "Da huy" << endl;
}