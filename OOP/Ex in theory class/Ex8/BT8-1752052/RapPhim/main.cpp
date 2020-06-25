#include "RapPhim.h"
// qui uoc: ghe nao so 0 la con trong, chua ai dat
// ghe nao so lon hon 0 tuc la co nguoi dat
// khi nhap de test thay hay nhap so 0 bieu thi cho ghe trong va cac con so bat ki de bieu thi cho ghe da co chu
int main()
{
	int m, n;
	cout << "Nhap so hang: ";
	cin >> m;
	cout << endl;
	cout << "Nhap so cot: ";
	cin >> n;
	cout << endl;
	
	RapPhimThuong rpt(m, n);
	rpt.Xuat();
	// kiem tra xem rap con trong hay da duoc dat (du chi 1 nguoi)
	if (rpt.Test() == 0)
		cout << "Rap con trong" << endl;
	else
		cout << "Rap da duoc dat" << endl;

	// kiem tra 1 ghe xem da dat hay con trong
	int i, j;
	cout << "Nhap vi tri hang ghe \n";
	cout << "Vi tri hang: ";
	cin >> i;//so hang
	cout << endl << "Vi tri cot: ";
	cin >> j;//so cot
	cout << endl;
	
	if (rpt.ViTriTrong(i-1, j-1) == 1)
		cout << "Ghe da duoc dat" << endl;
	else
		cout << "Ghe con trong" << endl;

	rpt.GheTrungTam();
	// xem gia tien 
	rpt.Gia(i-1, j-1);
	cout << rpt.TinhTongTien();
	rpt.DatVe(i, j);
	rpt.~RapPhimThuong();

	RapCaoCap rcc(m, n);

	// kiem tra xem rap con trong hay da duoc dat (du chi 1 nguoi)
	if (rcc.Test() == 0)
		cout << "Rap con trong" << endl;
	else
		cout << "Rap da duoc dat" << endl;

	// kiem tra 1 ghe xem da dat hay con trong
	int a, b;
	cout << "Nhap vi tri hang ghe \n";
	cout << "Vi tri hang: ";
	cin >> a;//so hang
	cout << endl << "Vi tri cot: ";
	cin >> b;//so cot
	cout << endl;

	if (rcc.ViTriTrong(a - 1, b - 1) == 1)
		cout << "Ghe da duoc dat" << endl;
	else
		cout << "Ghe con trong" << endl;

	rcc.GheTrungTam();
	// xem gia tien 
	rcc.Gia(a - 1, b - 1);
	cout << rcc.TinhTongTien();
	rcc.DatVe(a, b);
	rcc.~RapCaoCap();

	_getch();
	return 0;
}