#ifndef _Array_h
#define _Array_h

#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class IntArray
{
private:
	int size;
	int *array;
public:
	IntArray();
	IntArray(int size);
	IntArray& operator=(const IntArray &arr);
	int& operator[](int size);
	int GetSize();
	int GetArray();
	operator int();
	friend ostream& operator<<(ostream &os, const IntArray &arr);
	friend istream& operator>>(istream &is, IntArray &arr);
};
#endif