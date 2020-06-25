#include "Header.h"
#include<iostream>

void Nhap(PhanSo &p)
{
	cout << "Nhap tu: ";
	cin >> p.tu;
	do {
		cout << "Nhap mau: ";
		cin >> p.mau;
	} while (p.mau == 0);
}

//nhap day phan so
PhanSo Imports(int n)
{
	PhanSo p = (PhanSo)malloc(sizeof(PhanSo)*n);

	for (int i = 0; i<n; i++)
	{
		cout << "Phan so %d\n";
		cin >> i;
		array[i] = Nhap();
	}

	return p;
}


void Xuat(PhanSo &p)
{
	cout << "Phan so : " << p.tu << '/' << p.mau;
}

//in day phan so
void Prints(PhanSo p, int n)
{
	int i;

	cout << "\nDay phan so la:\n\t";
	for (i = 0; i < n - 1; i++)
	{
		Xuat(p.[i]);
		cout << ",";
	}

	Xuat(p[n - 1]);
}


//Kiem tra xem co phai la phan so
bool Test(PhanSo p)
{
	if (p.mau == 0);
		return -1;
	else
		return 0;

}

int UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return 0;
}

int RutGon(PhanSo &p)
{
	abs(p.tu);
	abs(p.mau);

	if (p.mau != 0) {
		int c = UCLN(p.tu, p.mau);
		p.tu = p.tu / c;
		p.mau = p.mau / c;
	}

	return c;
}

void NghichDao(PhanSo p)
{
	Test(p);
	int temp = p.tu;
	p.tu = p.mau;
	p.mau = temp;
}

int SoSanh(PhanSo p1, PhanSo p2)
{
	double thuong1 = p1.tu / (double)p1.mau;
	double thuong2 = p2.tu / (double)p2.mau;
	if (thuong1 > thuong2)
		return 1;
	if (thuong1 < thuong2)
		return -1;
	return 0;
}

PhanSo Sum(PhanSo p1, PhanSo p2)
{
	PhanSo sum;
	if (p1.mau != 0 && p2.mau != 0)
	{
		double tu = p1.tu * p2.mau + p2.tu * (double)p1.mau;
		double mau = p1.mau * p2.mau;
		sum = tu / mau;
	}
	return sum;
}

PhanSo Multiply(PhanSo p1, PhanSo p2)
{
	PhanSo multiply;
	int tu = p1.tu * p2.tu;
	int mau = p1.mau * p2.mau;
	multiply = tu / mau;
	return multiply;
}

//doi vi tri giua 2 phan so
void swap(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

template<class T> //T de tham so hoa kieu du lieu

//ham partition(phan hoach) chon phan tu pivot la phan tu dau tien cua day
PhanSo Partition(T array[], T left, T right)
{
	int p = array[left];//phan tu chot(pivot)
	last_S = left;//bat dau cua day S
	first_U = left + 1;//bat dau cua day Unknown, tam goi la day chua nhung con so khong biet cho sort

	while (first_U <= right)
	{
		if (array[first_U] < p)
		{
			swap(a[first_U], a[last_S + 1]);
			last_S + 1;
		}

		first_U++;
	}

	swap(array[left], array[last_S]);
}

template<class A> // tham so hoa kieu du lieu
//dung quick sort de sap xep tu nho den lon
PhanSo QuickSort(A array[], A left, A right)
{
	if (left == right)
		return;
	int pivotIndex = Partition(a[], left, right);
	QuickSort(array[], left, pivotIndex - 1);
	QuickSort(array[], pivotIndex + 1, right);

	return 0;
}

template<class B> //B de tham so hoa kieu du lieu
				  
//dung selection sort de sap xep tu lon den nho
PhanSo SelectionSort(B array[], B n)
{
	int i, j, pos, n;

	while (i < n - 1)
	{
		pos = n - 1;
		for (j = i; j < n; j--)
		{
			if (a[j] > a[pos])
				pos = j;
			if (i != pos)
				swap(a[i], a[pos]);
		}
		i++;
	}
}


