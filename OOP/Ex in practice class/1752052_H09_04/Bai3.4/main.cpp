#include "Header.h"

void main()
{
	B obj1("text");
	A *obj2 = new B(obj1);
	foo(&obj1, *obj2);

	_getch();
}