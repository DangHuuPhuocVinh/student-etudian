#include "Animal.h"

void Animal::Eat()
{
	eat = this->eat;
	cout << "Nhap an: ";
	while (cin.get() != '\n')
	{//empty
	}
	getline(cin, eat);
}

void Animal::Move()
{
	move = this->move;
	cout << endl;
	cout << "Nhap di chuyen: ";
	while (cin.get() != '\n')
	{//empty
	}
	getline(cin, move);
}

void Animal::GiveBirth()
{
	givebirth = this->givebirth;
	cout << endl;
	cout << "Nhap de: ";
	while (cin.get() != '\n')
	{//empty
	}
	getline(cin, givebirth);
}

void Animal::Boi()
{
	cout << "Boi" << endl;
}