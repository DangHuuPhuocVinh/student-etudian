#include "Lecturer.h"

int main()
{
	Lecturer *l;
	l = new TeachingAssistant;
	l->GetInfo();
	l->Output();
	l->Money();

	l = new Contract_base;
	l->GetInfo();
	l->Output();
	l->Money();





	_getch();
	return 0;
}