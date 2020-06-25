#include "DonThuc.h"

DonThuc::DonThuc()
{
	this->heso = 0;
	this->bien = x;
	this->somu = 1;
}

DonThuc::DonThuc(double hs, int sm)
{
	this->heso = hs;
	this->somu = sm;
	this->bien = x;
}

DonThuc DonThuc::operator+(const DonThuc &dt)
{
	DonThuc temp;
	if (this->bien == dt.bien && this->heso == dt.heso)
	{
		temp.heso = this->heso + dt.heso;
		temp.somu = this->somu;
		temp.bien = this->bien;
	}
	return temp;
}

DonThuc DonThuc::operator*(const DonThuc &dt)
{
	DonThuc temp;
	if (this->bien == dt.bien)
	{
		temp.heso = this->heso * dt.heso;
		temp.somu = this->somu + dt.somu;
		temp.bien = this->bien;
	}
	return temp;
}

int DonThuc::operator>(const DonThuc &dt)
{
	if (this->bien == dt.bien && this->somu == dt.somu)
	{
		if (this->heso > dt.heso)
			return 1;
		else
			return 0;
	}
}

int DonThuc::operator<(const DonThuc &dt)
{
	if (this->bien == dt.bien && this->somu == dt.somu)
	{
		if (this->heso < dt.heso)
			return 1;
		else
			return 0;
	}
}
int DonThuc::operator==(const DonThuc &dt)
{
	if (this->bien == dt.bien && this->somu == dt.somu)
	{
		if (this->heso == dt.heso)
			return 1;
		else
			return 0;
	}
}

int DonThuc::operator>=(const DonThuc &dt)
{
	if (this->bien == dt.bien && this->somu == dt.somu)
	{
		if (this->heso >= dt.heso)
			return 1;
		else
			return 0;
	}
}

int DonThuc::operator<=(const DonThuc &dt)
{
	if (this->bien == dt.bien && this->somu == dt.somu)
	{
		if (this->heso <= dt.heso)
			return 1;
		else
			return 0;
	}
}

DonThuc& DonThuc::operator=(const DonThuc &dt)
{
	this->heso = dt.heso;
	this->bien = dt.bien;
	this->somu = dt.somu;
	return *this;
}

DonThuc& DonThuc::operator+=(const DonThuc &dt)
{
	if (this->bien == dt.bien && this->somu == dt.somu)
	{
		this->heso = this->heso + dt.heso;
	}
	return *this;
}

DonThuc& DonThuc::operator*=(const DonThuc &dt)
{
	if (this->bien == dt.bien)
	{
		this->heso = this->heso * dt.heso;
		this->somu = this->somu + dt.somu;
	}
	return *this;
}

void DonThuc::operator++()
{
	cout << this->heso << this->bien << this->somu << " + 1" << endl;
}

void DonThuc::operator--()
{
	cout << this->heso << this->bien << this->somu << " - 1" << endl;
}

DonThuc& DonThuc::operator!()
{
	this->heso = this->heso * this->somu;
	this->somu -= 1;
	this->bien = this->bien;
	return *this;
}

double DonThuc::LayHeso()
{
	return this->heso;
}

char DonThuc::LayBien()
{
	return this->bien;
}

int DonThuc::LaySomu()
{
	return this->somu;
}

ostream& operator<<(ostream &os, const DonThuc &dt)
{
	os << dt.LayHeso << dt.LayBien  << dt.LaySomu;
	return os;
}

istream& operator>>(istream &is, const DonThuc &dt)
{
	is >> dt.LayHeso;
	is >> dt.LayBien;
	is >> dt.LaySomu;
	return is;
}