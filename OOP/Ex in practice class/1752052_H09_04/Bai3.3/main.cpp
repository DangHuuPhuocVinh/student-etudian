#include "Rescue.h"

int main()
{
	srand((int)time(0));
	HoangTu a;
	GiaiCuuCongChua b;
	a.Nhap();
	b.NhapDS();
	if (b.CuuCongChua(a) == 1)
		cout << "Rescued the princess" << endl;
	else 
		cout << "The prince died. Haha !!!" << endl;

	_getch();
	return 0;
}
