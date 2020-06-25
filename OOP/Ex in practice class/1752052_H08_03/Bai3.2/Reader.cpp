#include"Reader.h"

int DocGia::TinhTien()
{
	return 0;
}
DocGia::DocGia()
{
	this->HoTen = "Nguyen Van A";
	this->GioiTinh = "Nam";
	this->MaDocGia = 123456789;
	this->SoSachThang = 0;
}
DocGia::DocGia(string HoTen, int MaDocGia, string GioiTinh, int SoSach)
{
	this->GioiTinh = GioiTinh;
	this->MaDocGia = MaDocGia;
	this->HoTen = HoTen;
	this->SoSachThang = SoSach;
}
DocGia::DocGia(string HoTen, int MaDocGia, int SoSach)
{
	this->HoTen = HoTen;
	this->MaDocGia = MaDocGia;
	this->GioiTinh = "Nam";
	this->SoSachThang = 0;
	this->SoSachThang = SoSach;
}
DocGia::DocGia(const DocGia &p)
{
	this->GioiTinh = p.GioiTinh;
	this->HoTen = p.HoTen;
	this->MaDocGia = p.MaDocGia;
	this->SoSachThang = p.SoSachThang;
}



int DocGiaThuong::SoTien()
{
	int temp = this->SoSachThang * 5000;
	return temp;
}
int DocGiaVIP::SoTien()
{
	return 50000;
}
void DocGia::NhapDocGia()
{
	cout << "Nhap Ma Doc Gia: " << endl;
	cin >> this->MaDocGia;
	cout << "Ho va Ten: ";
	while (cin.get() != '\n')
	{//empty
	}
	getline(cin, this->HoTen);
	cout << "Nhap Gioi Tinh: ";
	getline(cin, this->GioiTinh);
}
void DocGiaThuong::NhapDocGia()
{
	DocGia::NhapDocGia();
	cout << " Nhap So Sach: ";
	cin >> this->SoSachThang;
}
void DocGiaVIP::NhapDocGia()
{
	DocGia::NhapDocGia();
	cout << "Nhap ngay het han: " << endl;
	while (cin.get() != 'n')
	{
		//empty
	}
	getline(cin, this->Date);
}
void DocGia::XuatDocGia()
{
	cout << "Ma Doc Gia: " << this->MaDocGia << endl;
	cout << "Ho va Ten: " << this->HoTen << endl;
	cout << "Gioi Tinh: " << this->GioiTinh << endl;
}
void DocGiaThuong::XuatDocGia()
{
	DocGia::XuatDocGia();
	cout << "So Thang Muon Sach: " << this->SoSachThang << endl;
}
void DocGiaVIP::XuatDocGia()
{
	DocGia::XuatDocGia();
	cout << " Ngay Het Han: " << this->Date << endl;
}