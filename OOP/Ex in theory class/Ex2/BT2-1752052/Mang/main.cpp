#include "MangSoNguyen.h"
#include<conio.h>

int main()
{
	int n, i, x; // n la so luong, i la vi tri, x la gia tri
	cin >> n;
	cin >> i;
	cin >> x;

	MangSoNguyen mang;

	mang.Nhap();
	mang.Xuat();
	mang.LayDoDai();
	mang.Gan(i, x);
	mang.Tim(x);
	mang.SapXepTangDan();
	mang.SapXepGiamDan();
	
	_getch();
	return 0;
}