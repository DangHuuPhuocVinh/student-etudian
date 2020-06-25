#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Point
{
private:
	double x;
	double y;
public:
	Point();
	Point(int hoanhdo, int tungdo);
	Point(int diem);
	Point(const Point &point);
	~Point();
};