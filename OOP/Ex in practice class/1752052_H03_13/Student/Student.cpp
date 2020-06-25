#include "Student.h"
#include<string.h>

Student::Student()
{
	this->code = 0;
	this->name = 0;
	this->gpa = 0;s
}

Student::Student(int code)
{
	this->code = code;
	this->gpa = 0;
	this->name = 0;
}

Student::Student(int code, double gpa)
{
	this->code = code;
	this->gpa = gpa;
	this->name = 0;
}

Student::Student(const Student &st)
{
	this->code = st.code;
	this->gpa = st.gpa;
	this->name = strdup(st.name);
}

Student::~Student()
{
	delete name;	
	cout << "Da huy" << endl;
}