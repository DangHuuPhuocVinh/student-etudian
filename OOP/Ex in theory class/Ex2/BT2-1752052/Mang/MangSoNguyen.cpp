#include "MangSoNguyen.h"
#include<conio.h>

#include <iostream>
#include <algorithm>
#include<functional>
#include <vector>
using namespace std;


MangSoNguyen MangSoNguyen::Nhap()
{
	cout << "Nhap so luong phan tu n : ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> this->songuyen[i];
	}
}

MangSoNguyen MangSoNguyen::Xuat()
{
	for (int i = 0; i < n; i++)
	{
		cout << "songuyen[" << i << "] = " << this->songuyen[i] << endl;
	}
}

int MangSoNguyen::LayDoDai()
{
	return this->n;
}

void MangSoNguyen::Gan(int i, int x) // i la vi tri, x la gia tri gan vao
{
	this->songuyen[i] = x;
}

int MangSoNguyen::Tim(int x) // x la so can tim
{
	for (int i = 0; i < n; i++)
		if (this->songuyen[i] == x)
			return i;
	return -1;
}

MangSoNguyen MangSoNguyen::SapXepTangDan(int n) // n la so luong phan tu trong mang
{
	int temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (this->songuyen[i] > this->songuyen[j]) //i va j la phan tu bat ki trong mang
			{
				this->songuyen[i] = temp;
				this->songuyen[i] = this->songuyen[j];
				this->songuyen[j] = temp;
			}
		}
}
MangSoNguyen MangSoNguyen::SapXepGiamDan(int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (this->songuyen[i] < this->songuyen[j])
			{
				this->songuyen[i] = temp;
				this->songuyen[i] = this->songuyen[j];
				this->songuyen[j] = temp;
			}
		}
}


