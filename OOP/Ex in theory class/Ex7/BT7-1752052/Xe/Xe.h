#pragma once
#ifndef _XE_H
#define _XE_H

#include<iostream>
#include<conio.h>

using namespace std;

class XeMay
{
protected:
	float SoLitXang;
	float SoTai;
	float SoKm;
public:
	//XeMay();
	float ChatHang();
	float LayHang();
	float SoXang();
	float SoKmXeChay();
	void XuatHang();
	bool KiemTraXeHetXang();
	void KiemTraXang();
};

class XeTai : public XeMay
{
public:
	void KiemTraXang();
};
#endif // !_XE_H
