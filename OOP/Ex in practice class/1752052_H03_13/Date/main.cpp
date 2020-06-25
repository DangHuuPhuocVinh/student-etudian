#include "Date.h"
#include<conio.h>

int main()
{
	Date d;
	Date();
	Date d1(02, 05, 2018);
	Date d2(d1);
	Date d(2018);
	d.~Date();

	_getch();
	return 0;
}