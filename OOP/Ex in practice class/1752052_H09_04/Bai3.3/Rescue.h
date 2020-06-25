#pragma once
#ifndef _RESCUE_H
#define _RESCUE_H


#include<iostream>
#include<conio.h>
#include<vector>
#include<ctime>

using namespace std;


class HoangTu
{
private:
	long int SoTien;
	int IQ;
	unsigned long int SucManh;
public:
	void Nhap();
	void Xuat();
	int SoSanhTien(int Tien);
	int SoSanhTriTue(int TriTue);
	int SoSanhSucMang(int SucManh);
	void ChinhTien(int Tien);
	void ChinhSucManh(int SucManh);
};
class Cong
{
private:
public:
	virtual void Nhap() = 0;
	virtual int quaCong(HoangTu& ht) = 0;
};
class CongLoai1 :public Cong
{
private:
	int DonGia;
	int SoLuong;
public:
	void Nhap();
	int quaCong(HoangTu& ht);
};
class CongLoai2 :public Cong
{
private:
	int TriTue;
public:
	void Nhap();
	int quaCong(HoangTu& ht);
};
class CongLoai3 : public Cong
{
private:
	int SucManh;
public:
	void Nhap();
	int quaCong(HoangTu& ht);
};
class GiaiCuuCongChua
{
private:
	vector<Cong*> a;
public:
	void NhapDS();
	int CuuCongChua(HoangTu& ht);
};

#endif