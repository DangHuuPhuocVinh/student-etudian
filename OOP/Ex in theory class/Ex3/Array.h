#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

template <class T>
class Array
{
private:
	int size;
	T *m_array;
public:
	Array();
	Array(int);
	Array(const Array &array);
	~Array();
};