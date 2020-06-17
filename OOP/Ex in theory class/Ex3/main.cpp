#include "Mang.h"
#include<conio.h>

void main()
{
	Array array;
	array.Array();
	Array(3);
	Array array(6);
	Array array2(array);

	Array *arr = new Array;//arr is array
	delete arr;

	_getch();
}
