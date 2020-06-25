#pragma once
#ifndef _RAPPHIM_H
#define _RAPPHIM_H

#include<iostream>
#include<conio.h>

using namespace std;

class RapPhimThuong
{
protected:
	int **ghe;
	int m; // so hang
	int n; // so cot
private:
	int gia = 80000;
public:
	RapPhimThuong(int m, int n);
	RapPhimThuong(const RapPhimThuong &r);
	void Xuat();
	RapPhimThuong& operator=(const RapPhimThuong &r);
	int Test();
	bool ViTriTrong(int i, int j);
	void GheTrungTam();
	void Gia(int i, int j);
	void DatVe(int i, int j);
	long int TinhTongTien();
	~RapPhimThuong();
};	
class RapCaoCap : public RapPhimThuong
{
private:
	float gia = 120000;
	int thu;
public:
	RapCaoCap(int m, int n) : RapPhimThuong(m, n) {}
	RapCaoCap(const RapCaoCap &rcc) : RapPhimThuong(rcc) {}
	RapCaoCap& operator=(const RapCaoCap &rcc)
	{
		RapPhimThuong::operator=(rcc);
	}
	void Gia(int a, int b);

};
#endif