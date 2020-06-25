#include "Xe.h"

/*
XeMay::XeMay()
{
	this->SoLitXang = 5;
	this->SoKm = 0;
	this->SoTai = 0;
	cout << "So lit xang ban dau: " << this->SoLitXang << endl;
	cout << "So km ban dau: " << this->SoKm << endl;
	cout << "So kg ma xe co ban dau: " << this->SoTai << endl;
} */

float XeMay::ChatHang()
{
	this->SoTai = 0; //so hang xe co ban dau
	cout << "Nhap so luong hang: ";
	cin >> this->SoTai;
	cout << endl;
	return this->SoTai;
}

float XeMay::LayHang()
{
	float kg;
	cout << "Nhap so hang can lay: ";
	cin >> kg;
	this->SoTai -= kg;
	return this->SoTai;
}

float XeMay::SoXang()
{
	this->SoLitXang = 5; // so lit xang ban dau xe co
	int solit;
	cout << "So xang do vao: ";
	cin >> solit;
	this->SoLitXang += solit;
	return this->SoLitXang;
}



float XeMay::SoKmXeChay()
{
	float km;
	this->SoKm = 0; //so km ban dau xe chay
	cout << "Nhap so km xe chay: ";
	cin >> km;
	this->SoKm += km;
	return this->SoKm;
}

bool XeMay::KiemTraXeHetXang()
{
	return this->SoLitXang > 0;
}

void XeMay::KiemTraXang()
{
	this->SoLitXang -= this->SoKm * 0.02 + this->SoTai * 0.01;
	cout << "So xang con lai: " << this->SoLitXang << endl;
}

void XeTai::KiemTraXang()
{
	this->SoLitXang -= this->SoKm * 0.2 + this->SoTai * 0.001;
	cout << "So xang con lai: " << this->SoLitXang << endl;
}

void XeMay::XuatHang()
{
	cout << "So hang con lai: " << this->SoTai << endl;
	cout << "So xang la: " << this->SoLitXang << endl;
	cout << "So km xe da chay: " << this->SoKm << endl;
}

