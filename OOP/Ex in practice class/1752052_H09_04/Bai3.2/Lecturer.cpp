#include "Lecturer.h"

void Lecturer::GetInfo()
{
	cout << "Nhap ho ten: ";
	/*while (cin.get() != '\n')
	{//empty
	}*/
	getline(cin, this->name);
	cout << "Nhap ID: ";
	cin >> this->ID;
	cout << "Nhap sdt: ";
	while (cin.get() != '\n')
	{//empty
	}
	getline(cin, this->telephone);
	cout << "Nhap dia chi: ";
	/*while (cin.get() != '\n')
	{//empty
	}*/
	getline(cin, this->address);
}

void Lecturer::Output()
{
	cout << "Ho ten giang vien: " << this->name << endl;
	cout << "So ID: " << this->ID << endl;
	cout << "So sdt: " << this->telephone << endl;
	cout << "Dia chi: " << this->address << endl;
}

void TeachingAssistant::GetInfo()
{
	Lecturer::GetInfo();
	cout << "Nhap so lop nhan: ";
	cin >> this->NumberOfClasses;
}

void TeachingAssistant::Output()
{
	Lecturer::Output();
	cout << endl << "So lop da nhan: " << this->NumberOfClasses;
}

void TeachingAssistant::Money()
{
	cout << endl << "Nhap so luong: ";
	cin >> this->Salary;
	double temp = this->Salary;
	double number = this->NumberOfClasses;
	//double salary = temp * number;
	cout << "Tien luong la: " << (temp * number);
}

void Contract_base::GetInfo()
{
	cout << endl << "Nhap so lop nhan: ";
	cin >> this->NumberOfClasses;
	cout << endl << "Nhap ti le luong: ";
	cin >> this->rate;
}

void Contract_base::Output()
{
	cout << endl << "So lop da nhan: " << this->NumberOfClasses;
	cout << endl << "Ti le luong: " << this->rate;
}

void Contract_base::Money()
{
	int number = this->NumberOfClasses;
	double rate = this->rate;
	cout << endl << "Luong la: " << (number * rate);
}


