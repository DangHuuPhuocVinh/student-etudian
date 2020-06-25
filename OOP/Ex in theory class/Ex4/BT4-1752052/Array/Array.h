#ifndef _Array_h
#define _Array_h

#pragma once
#include<iostream>
#include<conio.h>

using namespace std;
template <class T>
class Array
{
private:
	int size;
	T *array;
public:
	Array& operator=(const Array &arr);
	T& operator[](int size);
	operator(T)();
	int GetSize();
	T GetArray();
	friend ostream& operator<<(ostream &os, const Array &arr);
	friend istream& operator >> (istream &is, const Array &arr);
};
#endif