#pragma once
#ifndef _BASE_H
#define _BASE_H

#include<iostream>
#include<conio.h>

using namespace std;


class Base 
{
private:
	int t;
public:
	Base() {
		cout << "Base cons-0 param" << endl;
		t = 0;
	}
	Base(int u) {
		cout << "Base cons-1 param" << endl;
		t = u;
	}
	Base(const Base& b) {
		t = b.t;
		cout << "Base copy cons" << endl;
	}
	virtual ~Base() {
		cout << "Base destructor" << endl;
	}
	void print() {
		cout << "Base = " << t << endl;
	}
};
class DerivedA : public Base 
{
private:
	int a;
public:
	DerivedA() {
		cout << "DA cons - 0 param" << endl;
			a = 0;
	}
	DerivedA(int x) {
		cout << "DA cons - 1 param" << endl;
			a = x;
	}
	DerivedA(int u, int x) {
		cout << "DA cons - 2 params" << endl;
			a = x;
	}
	DerivedA(const DerivedA& da) {
		a = da.a;
	}
	~DerivedA() {
		cout << "DA destructor" << endl;
	}
	void print() {
		cout << "DA = " << a << endl;
	}

};
class DerivedB : public Base
{
private:
	float b;
public:
	DerivedB() {
		cout << "DB cons - 0 param" << endl;
			b = 0;
	}
	DerivedB(float x) {
		cout << "DB cons - 1 param" << endl;
			b = x;
	}
	DerivedB(int u, float x) :Base(u) {
		cout << "DB cons - 2 params" << endl;
			b = x;
	}
	DerivedB(const DerivedB& db) :Base(db) {
		cout << "DB copy cons" << endl;
			b = db.b;
	}
	~DerivedB() {
		cout << "DB destructor" << endl;
	}
	void print() {
		cout << "DB = " << b << endl;
	}

};

void f(Base b) {
	cout << "Function f" << endl;
	b.print();
}
#endif // !_BASE_H