#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Student
{
private:
	int code;
	char *name;
	double gpa;
public:
	Student();
	Student(int code);
	Student(int code, double gpa);
	Student(const Student &st);
	~Student();
};