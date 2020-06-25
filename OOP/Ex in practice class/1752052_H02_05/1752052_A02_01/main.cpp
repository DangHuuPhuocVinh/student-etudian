#include "Fraction.h"
#include<conio.h>

int main()
{
	Fraction f;

	f.Input();
	f.Output(&p);
	f.UCLN(a, b);
	cout << "Phan so da rut gon la: " << f.Reduce(&p) << endl;
	cout << "Tong 2 phan so la: " << f.Add() << endl; ;
	cout << "Hieu 2 phan so la: " << f.Subtract(p) << endl;
	f.Multiply(p);
	f.Divide(p);
	f.Sign(p);
	f.Compare(p);

	_getch();
	return 0;
}