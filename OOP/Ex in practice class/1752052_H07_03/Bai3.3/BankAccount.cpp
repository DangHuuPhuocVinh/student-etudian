#include "BankAccount.h"

void TaiKhoan::NhapSoTien()
{
	cout << "Nhap so tien: ";
	cin >> m_soDu;
	cout << endl;
}

float TaiKhoan::baoSoDu()
{
	return m_soDu;
}

void TaiKhoan::InSoDu()
{
	cout << "So du hien tai cua ban: " << m_soDu << endl;
}

void TaiKhoan::napTien(float soTien)
{
	m_soDu += soTien;
	cout << "So tien sau khi duoc nap: " << m_soDu << endl;
}

void TaiKhoan::rutTien(float soTien)
{
	do {
		if (soTien <= this->m_soDu)
		{
			this->m_soDu -= soTien;
		}
		else if (soTien > this->m_soDu)
		{
			cout << "So tien trong tai khoan khong du de rut" << endl;
			break;
		}
	} while (soTien > this->m_soDu);
}

void TaiKhoanTietKiem::KyHanGui()
{
	cout << "Vui long nhap ky han gui la so ngay gui";
	cout << "Nhap ky han gui: ";
	cin >> this->kyhan;
	cout << endl;
	cout << "So thang ky han cua ban la: " << this->kyhan << endl;
}

double TaiKhoanTietKiem::TienLai()
{
	if (this->kyhan <= 30)
		this->tienlai = this->m_soDu * 0.03 * this->kyhan / 360; // lai suat 3%
	else if (this->kyhan > 30 && this->kyhan <= 90)
		this->tienlai = this->m_soDu * 0.05 * this->kyhan / 360; // lai suat 5%
	else if (this->kyhan > 90 && this->kyhan <= 180)
		this->tienlai = this->m_soDu * 0.07 * this->kyhan / 360; // lai suat 7%
	else if (this->kyhan > 180)
		this->tienlai = this->m_soDu * 0.09 * this->kyhan / 360; // lai suat 9%
	return this->tienlai;
}

void TaiKhoanTietKiem::InTienLai()
{
	cout << "So tien lai cua ban la: " << this->tienlai << endl;
}

int TaiKhoanTietKiem::NhapSoThangDaGui()
{
	cout << "Nhap so thang ban da gui: " << endl;
	cin >> this->sothangdagui;
	return this->sothangdagui;
}
TaiKhoanTietKiem TaiKhoanTietKiem::TangSoThang()
{
	int sothangtang;
	cout << "Nhap so thang ban muon tang";
	cin >> sothangtang;
	cout << endl;
	this->sothangdagui += sothangtang;
	return *this;
}

void TaiKhoanTietKiem::rutTien(float soTien)
{
	float temp = TaiKhoan::baoSoDu();
	do
	{
		if (soTien <= TaiKhoan::baoSoDu())
		{
			temp -= soTien;
			float t = TienLai();
			this->sothangdagui = 0;
			t = 0;
			cout << "So du tai khoan hien tai : " << temp << endl;
			break;
		}
		else if (soTien > TaiKhoan::baoSoDu())
		{
			cout << "So tien trong tai khoan khong du de rut" << endl;
			break;
		}

	} while (soTien > TaiKhoan::baoSoDu());

}

void TaiKhoanTietKiem::napTien(float soTien)
{
	float temp = TaiKhoanTietKiem::baoSoDu();
	temp += soTien;
	this->sothangdagui = 0;
	float t = TienLai();
	t = 0;
	cout << "So du tai khoan hien tai : " << temp << endl;
}
