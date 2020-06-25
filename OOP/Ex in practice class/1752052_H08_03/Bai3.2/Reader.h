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
	DocGia();
	DocGia(string HoTen, int MaDocGia, string GioiTinh, int SoSach);
	DocGia(string HoTen, int MaDocGia, int SoSach);
	DocGia(const DocGia &p);
	int TinhTien();
	void NhapDocGia();
	void XuatDocGia();
};
class DocGiaThuong : public DocGia
{
private:
public:
	DocGiaThuong() : DocGia() {};
	DocGiaThuong(string HoTen, int MaDocGia, string GioiTinh, int SoSach) : DocGia(HoTen, MaDocGia, GioiTinh, SoSach) {};
	DocGiaThuong(string HoTen, int MaDocGia, int SoSach) : DocGia(HoTen, MaDocGia, SoSach) {};
	DocGiaThuong(const DocGia &p) : DocGia(p) {};
	void NhapDocGia();
	void XuatDocGia();
	int SoTien();
};
class DocGiaVIP : public DocGia
{
private:
	string Date;
public:
	DocGiaVIP() : DocGia() { this->Date = "1/1/1"; };
	DocGiaVIP(string HoTen, int MaDocGia, string GioiTinh, string Date) : DocGia(HoTen, MaDocGia, GioiTinh, 0) { this->Date = Date; };
	DocGiaVIP(string HoTen, int MaDocGia) : DocGia(HoTen, MaDocGia, 0) { this->Date = "1/1/1"; };
	DocGiaVIP(const DocGiaVIP &p) : DocGia(p) { this->Date = p.Date; };
	int SoTien();
	void NhapDocGia();
	void XuatDocGia();
};

#endif // !_READER_H
