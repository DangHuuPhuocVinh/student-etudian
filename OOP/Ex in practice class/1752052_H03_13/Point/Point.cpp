#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(double hoanhdo, double tungdo)
{
	this->x = hoanhdo;
	this->y = tungdo;
	cout << "Toa do diem la: (" << this->x << ", " << this->y << ")" << endl;
}

Point::Point(double diem)
{
	this->x = diem;
	this->y = 0;
}

Point::Point(const Point &point)
{
	this->x = point.x;
	this->y = point.y;
}

Point::~Point()
{
	cout << "Da huy" << endl;
}