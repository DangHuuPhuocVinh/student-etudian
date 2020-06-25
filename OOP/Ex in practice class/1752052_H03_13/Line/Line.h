#pragma once
#include<iostream>
#include<conio.h>

using namespace std;
class Point
{
public:
	double x; // x la hoanh do
	double y; // y la tung do
};
class Line
{
private:
	Point *start;
	Point *end;
public:
	Line();
	Line(const Line &l);
	Line(Point *startx, Point *starty);
	Line(Point *endx, Point *endy);
	~Line();
};