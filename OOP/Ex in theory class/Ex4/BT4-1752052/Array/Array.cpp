#include "Array.h"

template <classT>
Array& Array::operator=(const Array &arr)
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

template <class T>
T& Array<T>::operator[](int size)
{
	return this->array[size];
}

template <class T>
Array::operator(T)()
{
	return (T) array ;
}

int Array::GetSize()
{
	return this->size;
}

template <class T>
T Array<T>::GetArray()
{
	return this->array;
}

ostream& operator<<(ostream &os, const Array &arr)
{
	os << arr.size << arr->array;
	return os;
}

istream& operator>>(istream &is, const Array &arr)
{
	is >> arr.size;
	is >> arr->array;
	return is;
}
