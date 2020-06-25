#pragma once
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class NhanVien
{
private:
	string hoten;
	string cmnd;
	int manhanvien;
	string sdt;
	string diachi;
public:
	NhanVien();
	NhanVien(int ma);
	NhanVien(int ma, string cmnd, string ht);
	NhanVien(int ma, string cmnd, string ht, string sdt, string dc);
	void Nhap();
	void Xuat();
	int TinhLuong();
};

class NhanVienSanXuat : public NhanVien
{
private:
	int sosanpham; // so san pham lam duoc trong thang
public:
	NhanVienSanXuat(); //: NhanVien() {};
	NhanVienSanXuat(int ma);
	NhanVienSanXuat(int ma, string cmnd, string ht);
	NhanVienSanXuat(int ma, string cmnd, string ht, string sdt, string dc);
	NhanVienSanXuat(int ma, string cmnd, string ht, int ssp);
	NhanVienSanXuat(int ma, string cmnd, string ht, string sdt, string dc, int ssp);
	void Nhap();
	void Xuat();
	int TinhLuong();
};

class NhanVienCongNhat : public NhanVien
{
private:
	int songay; // so ngay lam viec trong thang
public:
	NhanVienCongNhat();
	NhanVienCongNhat(int ma);
	NhanVienCongNhat(int ma, string cmnd, string ht);
	NhanVienCongNhat(int ma, string cmnd, string ht, string sdt, string dc);
	NhanVienCongNhat(int ma, string cmnd, string ht, int ssp);
	NhanVienCongNhat(int ma, string cmnd, string ht, string sdt, string dc, int ssp);
	void Nhap();
	void Xuat();
	int TinhLuong();
};

#endif // !_EMPLOYEE_H
