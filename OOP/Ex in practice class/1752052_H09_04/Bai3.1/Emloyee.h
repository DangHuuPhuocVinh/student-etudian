#pragma once
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;

class NhanVien
{
private:
	string hoten;
	unsigned int cmnd;
	unsigned int manhanvien;
	unsigned int sdt;
	string diachi;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual int TinhLuong();
};

class CongTy
{
private:
	vector<NhanVien* > DSNV;
public:
	void Nhap();
	void Xuat();
	int TinhLuong();
};

class NhanVienSanXuat : public NhanVien
{
private:
	int sosanpham; // so san pham lam duoc trong thang
public:
	void Nhap();
	void Xuat();
	int TinhLuong();
};

class NhanVienCongNhat : public NhanVien
{
private:
	int songay; // so ngay lam viec trong thang
public:
	void Nhap();
	void Xuat();
	int TinhLuong();
};

#endif // !_EMPLOYEE_H