#include "IntArray.h"

IntArray::IntArray()
{
	this->size = NULL;
}

IntArray::IntArray(int size)
{
	this->size = size;
}

IntArray& IntArray::operator=(const IntArray &arr)
{
	if (this != &arr)
	{
		delete[]array;
		this->size = arr.size;
		this->array = new int[size];
		for (int i = 0; i < this->size; i++)
			this->array[i] = arr.array[i];
	}
	return *this;
}

int& IntArray::operator[](int size)
{
	return this->array[size];
}

IntArray::operator int()
{
	return (int) *array;
}


int IntArray::GetSize()
{
	size = this->size;
	return size;
}

int IntArray::GetArray()
{
	array =  this->array;
	return array;
}

ostream& operator<<(ostream &os, const IntArray &arr)
{
	os << arr.size << arr->array;
	return os;
}

istream& operator >> (istream &is, IntArray &arr)
{
	is >> arr.size;
	is >> arr->array;
	return is;
}