#include "Polynomial.h"


Polynomial::Polynomial()
{
	this->m_coefficient = new int(0);
}

Polynomial::Polynomial(const Polynomial &p)
{
	this->m_exponential = p.m_exponential;
	this->m_coefficient = new int[m_exponential + 1];
	for (int i = 0; i <= this->m_exponential; i++)
		this->m_coefficient = p.m_coefficient;
}

Polynomial::Polynomial(int exponential, int *coeff)
{
	delete[]m_coefficient;
	this->m_exponential = exponential;
	this->m_coefficient = new int[exponential + 1];
	for (int i = 0; i <= m_exponential; i++)
		this->m_coefficient[i] = coeff[i];
}

Polynomial::~Polynomial()
{
	delete m_coefficient;
}

ostream& operator<<(ostream &os, const Polynomial &p)
{
	for (int i = 0; i <= p.m_exponential; i++)
	{
		os << p.m_coefficient[i] << "x^" << i;
		if (i != p.m_exponential)
			os << " + ";
	}
	return os;
}

istream& operator>>(istream &is, Polynomial &p)
{
	cout << "Nhap vao bac cua da thuc: ";
	is >> p.m_exponential;

	p.m_coefficient = new int[p.m_exponential + 1];
	for (int i = 0; i <= p.m_exponential; i++)
	{
		cout << "He so " << i << " : ";
		is >> p.m_coefficient[i];
	}
	return is;
}

int Polynomial::GetCoefficient(int ex)
{
	return this->m_coefficient[ex];
}

int Polynomial::GetExponential()
{
	return this->m_exponential;
}

int Polynomial::Compare(const Polynomial &p)
{
	return this->m_exponential - p.m_exponential;
}

Polynomial Polynomial::CalDerivative()
{
	Polynomial p1;
	p1.m_coefficient = new int[m_exponential];
	p1.m_exponential = m_exponential - 1;
	for (int i = 0; i <= m_exponential - 1; i++)
		p1.m_coefficient[i] = m_coefficient[i + 1] * (i + 1);

	return p1;
}

Polynomial Polynomial::CalPrimitive()
{
	Polynomial p;
	p.m_coefficient = new int[m_exponential + 2];
	p.m_exponential = p.m_exponential + 1;
	for (int i = 1; i <= m_exponential + 1; i++)
		p.m_coefficient[i] = m_coefficient[i - 1] / i;

	return p;
}

Polynomial& Polynomial::operator+(const Polynomial &p)
{
	Polynomial p1;
	delete[] p1.m_coefficient;

	int DegMax = std::max(this->m_exponential, p.m_exponential);
	p1.m_exponential = DegMax;
	p1.m_coefficient = new float[DegMax + 1];

	int i = 0;
	while (i <= DegMax) {
		p1.m_coefficient[i] = 0;
		if (i <= this->m_exponential) p1.m_coefficient[i] += this->m_coefficient[i];
		if (i <= p.m_exponential) p1.m_coefficient[i] += p.m_coefficient[i];
		i++;
	}
	return p1;
}

Polynomial& Polynomial::operator-(const Polynomial &p)
{
	Polynomial p1;
	delete[] p1.m_coefficient;

	int degMax = std::max(this->m_exponential, p.m_exponential);
	p1.m_exponential = DegMax;
	p1.m_coefficient = new float[DegMax + 1];

	int i = 0;
	while (i <= DegMax) {
		p1.m_coefficient[i] = 0;
		if (i <= this->m_exponential) p1.m_coefficient[i] += this->m_coefficient[i];
		if (i <= p.m_exponential) p1.m_coefficient[i] -= p.m_coefficient[i];
		i++;
	}
	return p1;
}

Polynomial& Polynomial::operator*(const Polynomial &p) 
{
	Polynomial p1;
	delete[] p1.m_coefficient;

	int DegMax = this->m_exponential + p.m_exponential;
	p1.m_exponential = DegMax;
	p1.m_coefficient = new float[DegMax + 1];
	std::fill(p1.m_coefficient, p1.m_coefficient + DegMax + 1, 0);
	for (int i = 0; i <= this->m_exponential; i++)
		for (int j = 0; j <= p.m_exponential; j++) 
		{
			p1.m_coefficient[i + j] += this->m_coefficient[i] * p.m_coefficient[j];
		}
	return p1;
}

Polynomial& Polynomial::operator/(const Polynomial &p)
{
	if (this->m_exponential < p.m_exponential)
		return *this;
}

Polynomial& Polynomial::operator=(const Polymial &p)
{
	delete [] this->m_coefficient;
	this->m_exponential = p.m_exponential;
	this->m_coefficient = new float[this->m_exponential + 1];
	for(int i = 0; i <= p.m_exponential; i++)
	{
		this->m_coefficient[i] = p.m_coefficient[i];
	}
	return *this;
}

bool Polynomial::operator>(const Polynomial &p)
{
	return this->Compare(p) > 0;
}

bool Polynomial::operator<(const Polynomial &p)
{
	return this->Compare(p) < 0;
}

bool Polynomial::operator==(const Polynomial &p)
{
	return this->Compare(p) == 0;
}

bool Polynomial::operator>=(const Polynomial &p)
{
	return this->Compare(p) >= 0;
}

bool Polynomial::operator<=(const Polynomial &p) 
{
	return this->Compare(p) <= 0;
}

bool Polynomial::operator!=(const Polynomial &p)
{
	return this->Compare(p) != 0;
}

Polynomial Polynomial::operator!()
{
	return this->CalDerivative();
}

Polynomial Polynomial::operator~()
{
	return this->CalPrimitive();
}
