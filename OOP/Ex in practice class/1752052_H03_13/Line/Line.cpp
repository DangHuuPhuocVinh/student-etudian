#include "Line.h"
#include<string.h>

Line::Line()
{
	start == NULL;
	end == NULL;
}

Line::Line(Point *startx, Point *starty)
{
	this->start.x = strdup(startx);
	this->start.y = strdup(starty);
	this->end = NULL;
}

Line::Line(Point *endx, Point endy)
{
	this->end.x = strdup(endx);
	this->end.y = strdup(endy);
	this->start = NULL;
}

Line::Line(const Line &l)
{
	this->start.x = l.start.x;
	this->start = l.start.y;
	this->end.x = l.end.x;
	this->end.y = l.end.y;
}

Line::~Line()
{
	delete start;
	delete end;
	cout << "Line da huy" << endl;
}
