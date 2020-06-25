#include  "Rescue.h"

void GiaiCuuCongChua::NhapDS()
{
	int temp, r, temp1;
	temp = rand();
	if (temp > 10) temp = temp % 10;
	cout << "so luot cong la : " << temp << endl;
	Cong *p;
	for (int i = 0; i < temp; i++)
	{
		p = NULL;
		r = (rand() % 3);
		if (r == 0) p = new CongLoai1;
		else if (r == 1) p = new CongLoai2;
		else p = new CongLoai3;
		cout << "Thong tin cong : " << i + 1 << endl;
		p->Nhap();
		this->a.push_back(p);
	}
}

int GiaiCuuCongChua::CuuCongChua(HoangTu &ht)
{
	int flag = 1;
	for (int i = 0; i < this->a.size(); i++)
	{
		if (this->a[i]->quaCong(ht) == 0) 
			flag = 0;
	}
	return flag;
}

void HoangTu::Nhap()
{
	cout << "So Tien : ";
	cin >> this->SoTien;
	cout << endl << "Suc Manh : "; 
	cin >> this->SucManh;
	cout << endl << "Tri tue (IQ) : "; 
	cin >> this->IQ;
}
void HoangTu::Xuat()
{
	cout << "So tien ban hien co la : " << this->SoTien << endl;
	cout << "Suc manh cua ban hien tai la : " << this->SucManh << endl;
	cout << "Chi so thong minh ban luc nay la : " << this->IQ << endl;
}

int HoangTu::SoSanhSucMang(int SucManh)
{
	if (this->SucManh > SucManh)
		return 1;
	return 0;
}
void HoangTu::ChinhTien(int Tien)
{
	this->SoTien += Tien;
}

int HoangTu::SoSanhTien(int Tien)
{
	if (this->SoTien > Tien)
		return 1;
	return 0;
}

int HoangTu::SoSanhTriTue(int TriTue)
{
	if (this->IQ > TriTue)
		return 1;
	return 0;
}

void HoangTu::ChinhSucManh(int SucManh)
{
	this->SucManh += SucManh;
}

void CongLoai1::Nhap()//cong business
{
	cout << "Nhap Don Gia : ";
	cin >> this->DonGia;
	cout << endl;
	cout << "Nhap So Luong : ";
	cin >> this->SoLuong;
}

int CongLoai1::quaCong(HoangTu& ht)
{
	if(ht.SoSanhTien(this->DonGia * this->SoLuong)) 
		return 1;
	return 0;
}

void CongLoai2::Nhap()//cong academic
{
	cout << "Tri tue la : ";
	cin >> this->TriTue;
}

int CongLoai2::quaCong(HoangTu& ht)
{
	if(ht.SoSanhTriTue(this->TriTue)) 
		return 1;
	return 0;
}

void CongLoai3::Nhap()//cong power
{
	cout << endl;
	cout << "Suc manh la :";
	cin >> this->SucManh;
}

int CongLoai3::quaCong(HoangTu& ht)
{
	if (ht.SoSanhSucMang(this->SucManh))
		return 1;
	return 0;
}