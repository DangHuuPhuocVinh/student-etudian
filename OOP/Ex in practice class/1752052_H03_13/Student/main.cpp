#include "Student.h"
#include<conio.h>

int main()
{
	Student s;
	Student();
	s.Student(23);
	Student s1(23, 4.0);
	Student s2(s1);
	s.~Student();

	_getch();
	return 0;
}