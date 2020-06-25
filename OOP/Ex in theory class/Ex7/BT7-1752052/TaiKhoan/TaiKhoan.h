#pragma once
#ifndef _TAIKHOAN_H
#define _TAIKHOAN_H

#include<iostream>
#include<conio.h>

using namespace std;

class TaiKhoan
{
protected:
	float m_soDu;
public:
	void NhapSoTien();
	float baoSoDu();
	void InSoDu();
	void napTien(float soTien);
	void rutTien(float soTien);
};

class TaiKhoanTietKiem : public TaiKhoan
{
private:
	int kyhan;
	double tienlai;
	int sothangdagui;
public:
	void KyHanGui();
	double TienLai();
	void InTienLai();
	TaiKhoanTietKiem TangSoThang();
	int NhapSoThangDaGui();
	void rutTien(float soTien);
	void napTien(float soTien);
};
#endif // !_TAIKHOAN_H
