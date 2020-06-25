#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Time
{
private:
	int hour, minute, second;
public:
	Time();
	Time(int hour, int minute, int second);
	Time(const Time &t);
	Time(int hour);
	~Time();
};
