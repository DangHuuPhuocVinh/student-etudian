#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class MangSoNguyen
{
private:
	int songuyen[100];
	int n; // so phan tu trong mang
public:
	Mang() { n = 0; }//em tham khao tren mang
	~Mang() {}// em tham khao tren mang
	MangSoNguyen Nhap();
	MangSoNguyen Xuat();
	int LayDoDai();
	void Gan(int i, int x);
	int Tim(int x);
	MangSoNguyen SapXepTangDan();
	MangSoNguyen SapXepGiamDan();
};
