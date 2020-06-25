#include "Time.h"
#include<conio.h>

int main()
{
	//khoi tao mac dinh
	Time t;
	Time *q = new Time;

	Time();
	Time t1(00, 00, 00);
	Time t2(t1);
	Time t3(05);
	
	t.~Time();
	
	_getch();
	return 0;
}