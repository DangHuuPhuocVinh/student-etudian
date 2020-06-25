#include "Employee.h"

int main()
{
	NhanVien nv;
	nv.Nhap();
	nv.Xuat();
	
	cout << endl;

	NhanVienSanXuat nvsx;
	nvsx.Nhap();
	nvsx.Xuat();
	cout << "Tien luong la: " << nvsx.TinhLuong();

	cout << endl;

	NhanVienCongNhat nvcn;
	nvcn.Nhap();
	nvcn.Xuat();
	cout << "Tien luong la: " << nvcn.TinhLuong();

	_getch();
	return 0;
}