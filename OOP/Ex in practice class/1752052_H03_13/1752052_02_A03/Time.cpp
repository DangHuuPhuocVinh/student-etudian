#include "Time.h"

Time::Time()
{
	hour = 00;
	minute = 00;
	second = 00;
}

Time::Time(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}
Time::Time(const Time &t)
{
	this->hour = t.hour;
	this->minute = t.minute;
	this->second = t.second;
}

Time::Time(int hour)
{
	this->hour = hour;
	this->minute = 0;
	this->second = 0;
}

Time::~Time()
{
	cout << "Da huy" << endl;
}