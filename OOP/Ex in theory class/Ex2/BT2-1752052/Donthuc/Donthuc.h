#pragma once
#include<iostream>
#include<conio.h>
#include<math.h>


using namespace std;

// class don thuc 1 bien
class DonThuc
{
private:
	double x; // x la bien so chua he so
	int y; // y la bien so chua bien
	int z; // z la bien so chua so mu
public:
	DonThuc Nhap();
	DonThuc Lay();
	DonThuc Gan();
	DonThuc Sum(DonThuc dt);
	double Tinh();
	DonThuc DaoHam();
	DonThuc Multiply(DonThuc dt);
	int SoSanh(DonThuc dt);
};