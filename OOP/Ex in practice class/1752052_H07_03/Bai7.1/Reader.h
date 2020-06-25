#pragma once
#ifndef _READER_H
#define _READER_H

#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class DocGia
{
private:
	string HoTen;
	int MaDocGia;
	string GioiTinh;
protected:
	unsigned int SoSachThang;
public:
	int TinhTien();
	void NhapDocGia();
	void XuatDocGia();
};
class DocGiaThuong : public DocGia
{
private:
public:
	void NhapDocGia();
	void XuatDocGia();
	int SoTien();
};
class DocGiaVIP : public DocGia
{
private:
	string Date;
public:
	int SoTien();
	void NhapDocGia();
	void XuatDocGia();
};

#endif // !_READER_H