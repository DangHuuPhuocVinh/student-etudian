#include "Emloyee.h"
void CongTy::Nhap()
{
	int n; cout << " Nhap So Luong Nhan Vien : ";
	cin >> n;
	int type; 
	NhanVien *p;
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap NHAN VIEN thu " << i + 1 << endl;
		cout << "Nhap loai nhan vien 1 : NVCN 2 : NVSX : " << endl;
		cin >> type;
		p = NULL;
		if (type == 1)
		{
			p = new NhanVienCongNhat;
			
		}
		else if (type == 2)
		{
			p = new NhanVienSanXuat;
		}
		p->Nhap();
		this->DSNV.push_back(p);
	}
}
int CongTy::TinhLuong() {
	int sum = 0; 
	for (int i = 0; i < this->DSNV.size(); i++)
	{
		sum = sum + this->DSNV[i]->TinhLuong();
	}
	return sum;
}
void f1(NhanVien nv)
{
	cout << "NhanVien " << nv.TinhLuong() << endl;
}
void f2(NhanVien& nv)
{
	cout << "NhanVien" << nv.TinhLuong() << endl;
}
void f3(NhanVien *n)
{
	cout << "NhanVien " << n->TinhLuong() << endl;
}
void NhanVien::Nhap()
{
	cout << "Nhap ma nhan vien: \n";
	cin >> this->manhanvien;
	cout << "Nhap ho ten: " << endl;
	while (cin.get() != '\n')
	{//empty
	}
	getline(cin, this->hoten);
	cout << "Nhap so CMND: \n";
	cin >> this->cmnd;
	cout << "Nhap so dien thoai: \n";
	cin >> this->sdt;
	cout << "Nhap dia chi: \n";
	while (cin.get() != '\n')
	{
	}
	getline(cin, this->diachi);
}

void NhanVien::Xuat()
{
	cout << endl;
	cout << "Ma so nhan vien la: " << this->manhanvien << endl;
	cout << "Ho ten nhan vien la: " << this->hoten << endl;
	cout << "So dien thoai nhan vien la: " << this->sdt << endl;
	cout << "So cmnd la: " << this->cmnd << endl;
	cout << "Dia chi la: " << this->diachi << endl;
}

int NhanVien::TinhLuong()
{
	return 0;
}

void NhanVienSanXuat::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap so san pham lam duoc: \n";
	cin >> this->sosanpham;
}

void NhanVienSanXuat::Xuat()
{
	NhanVien::Xuat();
	cout << "So san pham lam duoc la: " << this->sosanpham << endl;
}

int NhanVienSanXuat::TinhLuong()
{
	int sosanpham = this->sosanpham;
	int luong = sosanpham * 10000;
	return luong;
}

void NhanVienCongNhat::Nhap()
{
	cout << endl;
	NhanVien::Nhap();
	cout << "Nhap so ngay lam viec trong thang: \n";
	cin >> this->songay;
}

void NhanVienCongNhat::Xuat()
{
	NhanVien::Xuat();
	cout << "So ngay lam viec trong thang la: " << this->songay << endl;
}

int NhanVienCongNhat::TinhLuong()
{
	int songay = this->songay;
	int luong = songay * 300000;
	return luong;
}