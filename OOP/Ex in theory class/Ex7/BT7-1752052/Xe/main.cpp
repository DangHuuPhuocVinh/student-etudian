#include "Xe.h"
#include<conio.h>

int main()
{
	
	XeMay xm;

	xm.ChatHang();
	xm.LayHang();
	xm.SoXang();
	xm.SoKmXeChay();
	xm.XuatHang();
	xm.KiemTraXang();
	if (xm.KiemTraXeHetXang() == true)
		cout << "Xe con xang" << endl;
	else
		cout << "Xe het xang. Vui long do xang" << endl;

	XeTai xt;
	xt.ChatHang();
	xt.LayHang();
	xt.SoXang();
	xt.SoKmXeChay();
	xt.XuatHang();
	xt.KiemTraXang();
	if (xt.KiemTraXeHetXang() == true)
		cout << "Xe con xang" << endl;
	else
		cout << "Xe het xang. Vui long do xang" << endl;

	_getch();
	return 0;
}