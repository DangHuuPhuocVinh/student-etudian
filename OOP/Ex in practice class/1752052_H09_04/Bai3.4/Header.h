#pragma once
#ifndef _HEADER_H
#define _HEADER_H

#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class A
{
private:
	char *m_s;
public:
	A(){
		m_s = strdup("default");
	}
	A(const A &a) {
		this->m_s = new int;
		this->m_s = a;
	}
	A(char *s) { m_s = s; }
	virtual void prepare() { cout << "A "; }
	void display()
	{
		prepare();
		cout << m_s << endl;
	}
	~A() { delete m_s; }
};
class B : public A
{
public:
	B(char *s) : A(s) {}
	B(const B &b) {} : A(a);
	void prepare() { cout << "B "; }
};

void foo(A *obj1, A obj2)
{
	obj1->display();
	obj2.display();
}

#endif // !_HEADER_H
