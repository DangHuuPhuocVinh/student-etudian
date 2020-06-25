#ifndef _DonThuc_h
#define _DonThuc_h

#pragma once

#include<iostream>
#include<conio.h>

using namespace std;

class DonThuc
{
private:
	double heso;
	char bien;
	int somu;
public:
	DonThuc();
	DonThuc(double hs, int sm); // hs la he so, sm la so mu
	DonThuc operator+(const DonThuc &dt);
	DonThuc operator*(const DonThuc &dt);
	int operator>(const DonThuc &dt);
	int operator<(const DonThuc &dt);
	int operator==(const DonThuc &dt);
	int operator>=(const DonThuc &dt);
	int operator<=(const DonThuc &dt);
	int operator!=(const DonThuc &dt);
	DonThuc operator=(const DonThuc &dt);
	DonThuc operator+=(const DonThuc &dt);
	DonThuc operator*=(const DonThuc &dt);
	void DonThuc::operator++();
	void DonThuc::operator--();
	double LayHeso();
	char LayBien();
	int LaySomu();
	DonThuc& operator!();
	friend ostream& operator<<(ostream &os, const DonThuc &dt);
	friend istream& operator >> (istream &is, const DonThuc &dt);
};
#endif