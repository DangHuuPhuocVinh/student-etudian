#pragma once
#ifndef _RBG_H
#define _RBG_H

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class RGB
{
private:
	int red;
	int green;
	int blue;
public:
	RGB();
	void Gan(const char* mau);
	void check();
	RGB& operator+(RGB p);
	RGB& operator+(int i);
	friend RGB operator+(int i, RGB p);
	RGB operator-(int i);
	friend ostream& operator<<(ostream& ouput, RGB p);
};

class Pic
{
private:
	RGB **pic;
	int m, n; // m la hang con n la cot
public:
	Pic(int m, int n);
	Pic TangSang(int pixel);
	Pic GiamSang(int pixel);
};

#endif 
