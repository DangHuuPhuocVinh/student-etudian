#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Point
{
	double x; // x la hoanh do
	double y; // y la tung do
};

class Triangle
{
private:
	Point *A;
	Point *B;
	Point *C;
public:
	Triangle();
	Triangle(Point *Ax, Point *Ay);
	Triangle(Point *Bx, Point *By);
	Triangle(Point *Cx, Point *Cy);
	~Triangle();
};