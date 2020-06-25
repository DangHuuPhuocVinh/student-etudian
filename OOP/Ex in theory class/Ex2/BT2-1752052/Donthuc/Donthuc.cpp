#include "Donthuc.h"
#include<iostream>

DonThuc DonThuc::Nhap()
{
	cout << "Nhap he so: " << endl;
	cin >> this->x;
	cout << "Nhap bien: " << endl;
	cin >> this->y;
	cout << "Nhap so mu: " << endl;
	cin >> this->z;
}

//ham lay he so, so mu
DonThuc DonThuc::Lay();
{
	return this->x;
	return this->z;
}

DonThuc DonThuc::Gan()
{
	int heso, somu;
	return heso = this->x;
	return somu = this->z;
}

DonThuc DonThuc::Sum(DonThuc dt)
{
	int sum;
	return sum = this->x + dt.x;
}

double DonThuc::Tinh();
{
	double giatri = pow(y, z);//gia tri cua phep mu
	double ketqua = giatri * x;
	return ketqua;
}

// dao ham son thuc x co qui tac
DonThuc DonThuc::DaoHam()
{
	return this->x = this->x * this->z;
	return this->z = this->z - 1;
}

DonThuc DonThuc::Multiply(DonThuc dt)
{
	float heso = this->x * dt.x;
	int somu = this->z + dt.z
}

int DonThuc::SoSanh(DonThuc dt)
{
		DonThuc giatri1 = Tinh(this);
		DonThuc giatri2 = Tinh(dt);
		if (giatri1 > giatri2)
			return 1;
		if (giatri1 < giatri2)
			return -1;
		return 0;
}