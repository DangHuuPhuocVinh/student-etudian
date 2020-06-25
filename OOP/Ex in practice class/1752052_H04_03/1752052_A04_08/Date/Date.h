#pragma once

#pragma once
#ifndef _Date_h
#define _Date_h

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
	Date(int year);
	Date(int year, int month);
	Date(int year, int month, int day);
	Date(const Date &d);
	Date Tomorrow();
	Date Yesterday();
	int CheckLeapYear();
	int operator>(const Date &d);
	int operator<(const Date &d);
	int operator>=(const Date &d);
	int operator<=(const Date &d);
	int operator==(const Date &d);
	int operator!=(const Date &d);
	Date& operator=(const Date &d);
	Date& operator+=(int days);
	Date& operator-=(int days);
	Date operator+(Date d);
	Date operator-(Date d);
	Date& operator++();
	Date operator++(int x);
	Date& operator--();
	Date operator--(int x);
	operator int();
	operator float();
	int GetDay();
	int GetMonth();
	int GetYear();
	friend ostream& operator<<(ostream &os, const Date &d);
	friend istream& operator >> (istream &is, Date &d);

};
#endif 

