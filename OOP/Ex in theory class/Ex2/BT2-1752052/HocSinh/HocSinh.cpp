#include "HocSinh.h"
#include<conio.h>

#include<string>

HocSinh HocSinh::Nhap()
{
	cout << "Nhap ho ten: " << endl;
	getline(cin, this->Hoten;
	cout << "Nhap diem toan: " << endl;
	cin >> this->toan;
	cout << "Nhap diem van: " << endl;
	cin >> this->van;
}

//ham lay hoten, diem van va toan
HocSinh HocSinh::Lay()
{
	return this->Hoten;
	return this->van;
	return this->toan;
}

HocSinh HocSinh::Gan()
{
	string hoten;
	float x, y;
	return hoten = this->Hoten;
	return x = this->van; // x la bien chua gia tri diem van
	return y = this->toan; // y la bien chua gia tri diem toan
}

float HocSinh::DiemTb(float x, float y)
{
	float dtb; // dtb la bien chua diem trung binh
	return dtb = (x + y) / 2;
}

HocSinh HocSinh::Xeploai(float dtb);
{
	if (dtb >= 8)
		cout << "Gioi" << endl;
	if (dtb >= 7 && dtb < 8)
		cout << "Kha" << endl;
	if (dtb >= 5 && dtb < 7)
		cout << "Trung binh" << endl;
	if (dtb < 5)
		cout << "Yeu" << endl;
}