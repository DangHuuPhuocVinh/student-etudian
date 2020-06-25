#pragma once
#include<iostream>
#include<conio.h>
#include<string>

using namespace std;
class HocSinh
{
private:
	string Hoten;
	int van, toan;
public:
	HocSinh Nhap();
	HocSinh Lay();
	HocSinh Xuat();
	HocSinh Gan();
	float DiemTb(float x, float y);
	HocSinh Xeploai(float dtb);
};