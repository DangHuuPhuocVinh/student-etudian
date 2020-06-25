#include "TaiKhoan.h"
#include<conio.h>

int main()
{
	TaiKhoan tk;
	tk.NhapSoTien();
	tk.baoSoDu();
	tk.InSoDu();

	TaiKhoanTietKiem tktc;

	float soTien;
	tktc.baoSoDu();
	tktc.InSoDu();
	tktc.TienLai();
	tktc.InTienLai();
	//nap
	cout << "Nhap so tien nap vao : ";
	cin >> soTien;
	tktc.napTien(soTien);
	//rut
	cout << "Nhap so tien can rut : ";
	cin >> soTien;
	tktc.rutTien(soTien);

	tktc.TangSoThang();
	tktc.TienLai();
	tktc.InTienLai();
	tktc.baoSoDu();
	tktc.InSoDu();

	_getch();
	return 0;
}