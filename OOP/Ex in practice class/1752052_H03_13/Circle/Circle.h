#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Point
{
private:
	double x; //  x la hoanh do
	double y; // y la tung do
};

class Circle
{
private:
	Point *center;
	double radius;
public:
	Circle();
	Circle(double radius);
	Circle(Point *centerx, Point *centery);
	Circle(const Circle &circle);
	~Circle();

};