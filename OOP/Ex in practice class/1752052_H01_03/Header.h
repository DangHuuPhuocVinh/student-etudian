#pragma once
#include<iostream>
#include<conio.h>
#include<math.h>
#include "Header.h"

using namespace std;

struct PhanSo
{
	int tu;
	int mau;
};

void Nhap(PhanSo &p);
PhanSo Imports(int n);
bool Test(PhanSo p);
int UCLN(int a, int b);
void RutGon(PhanSo &p);
void Xuat(PhanSo &p);
void Prints(PhanSo p, int n);
void NghichDao(PhanSo p);
int SoSanh(PhanSo p1, PhanSo p2);
PhanSo Sum(PhanSo p1, PhanSo p2);
PhanSo Multiply(PhanSo p1, PhanSo p2);
void swap(int a, int b);
template<class T>
void Partition(T array[], T left, T right);
template<class A>
PhanSo QuickSort(A array[], A left, A right);
template<class A>
PhanSo SelectionSort(B array[], B n);

