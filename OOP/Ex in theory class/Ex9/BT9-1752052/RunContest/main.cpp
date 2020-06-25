#include "RunContest.h"

int main()
{
	Animal *a;
	Cheetah c;
	Antelope an;
	Lion l;
	Human h;
	Dog d;
	Horse hs;
	//a->RunContest(&c, &l);
	if (RunContest(&d, &hs) == 1)
		cout << "Dog win";
	else if (RunContest(&d, &hs) == 0)
		cout << "Horse win";
	else
		cout << "draw";

	_getch();
	return 0;
}