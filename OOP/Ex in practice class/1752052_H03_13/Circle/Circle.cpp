#include "Circle.h"
#include<string.h>

Circle::Circle()
{
	this->center = NULL;
	this->radius = 0;
}

Circle::Circle(double radius)
{
	this->center = NULL;
	this->radius = radius;
}

Circle::Circle(Point *centerx, Point *centery)
{
	this->center.x = strdup(centerx);
	this->center.y = strdup(centery);
	this->radius = 0;
}

Circle::Circle(const Circle &circle)
{
	this->center.x = circle.center.x;
	this->circle.y = circle.center.y;
	this->radius = circle.radius;
}

Circle::~Circle()
{
	delete center;
	cout << "Da huy" << endl;
}