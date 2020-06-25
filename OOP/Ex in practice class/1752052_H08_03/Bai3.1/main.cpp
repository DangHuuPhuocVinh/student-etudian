#include "Employee.h"

int main()
{
	
	NhanVien nv;
	nv.Xuat();
	NhanVien nv1(5);
	nv1.Xuat();
	NhanVien nv2(3, "0705220", "Nguyen Hue");
	nv2.Xuat();
	NhanVien nv3(4, "05504055", "Tran Hung Dao", "0660504", "Tran Hung Dao quan 1");
	nv3.Xuat();
	
	NhanVienSanXuat nvsx;
	nvsx.Xuat();
	NhanVienSanXuat nvsx1(5);
	nvsx1.Xuat();
	NhanVienSanXuat nvsx2(7, "050201", "Luong The Vinh");
	nvsx2.Xuat();
	NhanVienSanXuat nvsx3(8, "02205", "Hai Ba Trung", "0505005", "Hai Ba Trung quan 1");
	nvsx3.Xuat();
	NhanVienSanXuat nvsx4(10, "122547", "Ly Thuong Kiet", 30);
	nvsx4.Xuat();
	NhanVienSanXuat nvsx5(50, "15458799", "Ngo Quyen", "0155045", "Ngo Quyen quan 10", 55);
	nvsx5.Xuat();

	NhanVienCongNhat nvcn;
	nvcn.Xuat();
	NhanVienCongNhat nvcn1(5);
	nvcn1.Xuat();
	NhanVienCongNhat nvcn2(55, "5520504", "Ho Chi Minh");
	nvcn2.Xuat();
	NhanVienCongNhat nvcn3(1, "0000001", "An Duong Vuong", "khong co", "An DUong Vuong quan 5");
	nvcn3.Xuat();
	NhanVienCongNhat nvcn4(60, "2151551", "Nguyen Trai", 56);
	nvcn4.Xuat();
	NhanVienCongNhat nvcn5(85, "0100200104", "Gia Long", "khong co", "khong co", 62);
	nvcn5.Xuat();

/*	NhanVien nv;
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
*/
	_getch();
	return 0;
}