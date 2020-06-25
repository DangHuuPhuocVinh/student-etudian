#pragma once

#include<iostream>
#include<conio.h>

using namespace std;

template  <class T>
class 2DArray
{
private:
	T **data;
	int m, n;
public:
	2DArray()
	{
		int m = n = 0;
		T **data = NULL;
	}

	2DArray(int m, int n)
	{
		this->m = m;
		this->n = n;
		data = new T*[m];
		for (int i = 0; i <= m; i++)
			data[i] = new T[n];
	}

	2DArray(int m, int n)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = 0;
	}

	2DArray(int n)
	{
		for (int i = 0; i < n; i++)
			a[i][j] = 0;
	}

	2DArray(const 2DArray &arr)
	{
		this->m = arr.m;
		this->n = arr.n;
		this->data = new T *[this->m];
		for (int i = 0; i < this->m; i++)
			this->data[i] = new T[this->n];
	}
	template <class T1>
	friend ostream& operator<<(ostream &os, const 2DArray<T1> &ar);
	template <class T1>
	friend istream& operator>>(istream &is, 2DArray<T1> &ar);
	~2DArray()
	{
		for (int i = 0; i < this->m; i++)
			delete[] this->data[i];
		delete[] this->data;
	}

	void Output()
	{
		for (int i = 0; i < this->m; i++)
		{
			cout << "\n\t";
			for (int j = 0; j < this->n; j++)
				cout << setw(5) << data[i][j] << " ";
		}
		cout << endl;
	}

	void Input()
	{
		for (int i = 0; i < this->m; i++)
			for (int j = 0; j < this->n; j++)
			{
				cout << "\tPhan tu [" << i + 1 << "," << j + 1 << "] = ";
				cin >> data[i][j];
			}
	}

	T& operator=(const 2DArray &arr)
	{
		this->m = arr.m;
		this->n = arr.n;
		this->data = new T *[this->m];
		for (int i = 0; i < this->m; i++)
			this->data[i] = new T[this->n];
	}

	int operator==(const 2DArray &arr)
	{
		if (this->m == arr.m)
		{
			if (this->n == arr.n)
			{
				for (int i = 0; i < m; i++)
					for (int j = 0; j < n; j++)
					{
						data[i][j] == arr.data[i][j];
						return 1;
					}
			}
		}
		return 0;
	}

	int operator!=(const 2DArray &arr)
	{
		if (this->m == arr.m)
		{
			if (this->n == arr.n)
			{
				for (int i = 0; i < m; i++)
					for (int j = 0; j < n; j++)
					{
						data[i][j] != arr.data[i][j];
						return 1;
					}
			}
		}
		else if (this->m != arr.m)
				return 1;
		else if (this->n != arr.n)
				return 1;
		return 0;
	}

	2DArray operator+(int number)
	{
		int temp;
		for(int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				temp.data[i][j] += number;
			}
		return temp;
	}
	
	2DArray operator+(const 2DArray &arr)
	{
		int temp;
		if (this->m != arr.m)
			return;
		else if (this->n != arr.n)
			return;
		else
		{
			for(int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					temp.data[i][j] += arr.data[i][j];
				}
		}
		return temp;
	}

	2DArray operator-(int number)
	{
		int temp;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				temp.data[i][j] -= number;
			}
		return temp;
	}

	2DArray operator-(const 2DArray &arr)
	{
		int temp;
		if (this->m != arr.m)
			return;
		else if (this->n != arr.n)
			return;
		else
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					temp.data[i][j] -= arr.data[i][j];
				}
		}
		return temp;
	}

	2DArray operator*(int number)
	{
		int temp;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				temp.data[i][j] *= number;
			}
		return temp;
	}

	2DArray operator/(int number)
	{
		int temp;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				temp.data[i][j] /= number;
			}
		return temp;
	}

	2DArray operator+=(int number)
	{
		int temp;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				temp.data[i][j] += number;
			}
		return temp;
	}

	2DArray& operator+=(const 2DArray &arr)
	{
		if (this->m != arr.m)
			return;
		else if (this->n != arr.n)
			return;
		else
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					this->data[i][j] += arr.data[i][j];
				}
		}
		return *this;
	}

	2DArray operator-=(int number)
	{
		int temp;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				temp.data[i][j] -= number;
			}
		return temp;
	}

	2DArray& operator-=(const 2DArray &arr)
	{
		if (this->m != arr.m)
			return;
		else if (this->n != arr.n)
			return;
		else
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					this->data[i][j] -= arr.data[i][j];
				}
		}
		return *this;
	}

	2DArray& operator*=(const 2DArray &arr)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				this->data[i][j] *= arr.data[i][j];
			}
		return *this;
	}

	2DArray& operator/=(const 2DArray &arr)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				this->data[i][j] /= arr.data[i][j];
			}
		return *this;
	}
};   

template <class T1>
ostream& operator<<(ostream &os, 2DArray &ar)
{
	os << "So hang: " << ar.m << endl;
	os << "So cot: " << ar.n << endl;
	for (int i = 0; i < ar.m; i++)
	{
		for (int i = 0; i < ar.n; i++)
		{
			os << ar.data[i][j];
		}
	}
	return os;
}

template <class T1>
istream& operator >> (istream &is, 2DArray<T1> &ar)
{
	is >> ar.m;
	is >> ar.n;
	for (int i = 0; i < ar.m; i++)
	{
		for (int i = 0; i < ar.n; i++)
		{
			os >> ar.data[i][j];
		}
	}
	return is;
}

template <class T>
int main()
{
	template <class T>
	2DArray<T> a();
	int number;
	2DArray<T> a1(2, 3);
	2DArray<T> a2 = a1;

	cout << "Tong la: " << a1 + a2 << endl;
	cout << "Hieu la: " << a1 - a2 << endl;
	cout << "Tich la: " << a1 * a2 << endl;
	cout << "Thuong la: " << a1 / a2 << endl;

	cout << "Nhap so bat ki: " << endl;
	cin >> number;

	cout << a1 + number << endl;
	cout << a1 - number << endl;
	cout << a1 * number << endl;
	cout << a1 / number << endl;

	cout << a1 += 2;
	cout << a1 -= 2;
	cout << a1 *= 2;
	cout << a1 /= 2;

	a1.~2DArray();

	_getch();
	return 0;
}