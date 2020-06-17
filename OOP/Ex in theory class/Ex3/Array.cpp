#include "Mang.h"
template <class T>
Array<T>::Array()
{
	this->size = 0;
	m_array = new int[size];
	cout << "Mang da duoc khoi tao" << endl;
}

template <class T>
Array<T>::Array(int n) //n la kich thuoc cho truoc
{
	this->size = n;
	m_array = new int[size];
	for (int i = 0; i <= size; i++)
		m_array[i] = 0;
}

template <class T>
Array<T>::Array(int n) //n la kich thuoc cho truoc
{
	this->size = n;
	array = new int[size];
	for (int i = 0; i <= size; ++i)
		m_array[i] = 0;
}

template <class T>
Array<T>::Array(const Array &array)
{
	this->size = array.size;
	*array = new int[array.size];
	for (int i = 0; i <= size; ++i)
		array[i] = array.m_array[i]; 
}

template <class T>
Array<T>::~Array();
{
	this->size = 0;
	delete m_array;
	cout << "Mang da xoa" << endl;
}