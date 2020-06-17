#include "Polynomial.h"
#include<conio.h>

int main()
{
	Polynomial p1, p2;
	Polynomial p1(2);
	Polynomial p2(p1);
	int x;

	cin >> p;
	cin >> p1;
	cout << p << endl;

	cout << "Bac can kiem he so: ";
	cin >> x;
	cout << "He so " << x << " : " << p.getCoefficient(2) << endl;

	cout << "Bac cua da thuc: " << p.getExponential() << endl;

	if (p.compare(p1) > 0)
		cout << "Da thuc " << p << " lon hon da thuc " << p1 << endl;
	else if (p.compare(p1) == 0)
		cout << "Da thuc " << p << " bang da thuc " << p1 << endl;
	else
		cout << "Da thuc " << p << " be hon da thuc " << p1 << endl;


	p1 + p2;
	p1 - p2;
	p1 * p2;
	p1 / p2;


	_getch();
	return 0;
}