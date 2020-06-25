#include "Triangle.h"
#include<string.h>

Triangle::Triangle()
{
	this->A = NULL;
	this->B = NULL;
	this->C = NULL;
}

Triangle::Triangle(Point *Ax, Point *Ay)
{
	this->A.x = strdup(Ax);
	this->A.y = strdup(Ay);
	this->B = NULL;
	this->C = NULL;
}

Triangle::Triangle(Point *Bx, Point *By)
{
	this->B.x = strdup(Bx);
	this->B.y = strdup(By);
	this->A = NULL;
	this->C = NULL;
}

Triangle::Triangle(Point *Cx, Point *Cy)
{
	this->C.x = strdup(Cx);
	this->C.y = strdup(Cy);
	this->A = NULL;
	this->B = NULL;
}


Triangle::~Triangle()
{
	delete A;
	delete B;
	delete C;
	cout << "Da huy" << endl;
}
