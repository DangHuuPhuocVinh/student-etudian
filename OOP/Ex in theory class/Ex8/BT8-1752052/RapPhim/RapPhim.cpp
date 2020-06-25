#include "RapPhim.h"

RapPhimThuong::RapPhimThuong(int m, int n)
{
	this->m = m;
	this->n = n;
	this->ghe = new int*[this->m];

	for (int i = 0; i < this->m; i++)
	{
		this->ghe[i] = new int[this->n];
		for (int j = 0; j < this->n; j++)
		{
			cin >> this->ghe[i][j];
		}
		cout << endl;
	}
}

RapPhimThuong::RapPhimThuong(const RapPhimThuong &r)
{
	for (int i = 0; i < this->m; i++)
	{
		delete[] this->ghe[i];
	}
	delete[] this;

	this->m = r.m;
	this->n = r.n;
	this->ghe = new int*[this->m];

	for (int i = 0; i < this->m; i++)
	{
		this->ghe[i] = new int[this->n];
	}
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
		{
			this->ghe[i][j] = r.ghe[i][j];
		}
}

void RapPhimThuong::Xuat()
{
	cout << "Hang ghe\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << this->ghe[i][j] << " ";
		}
		cout << "\n";
	}
}

int RapPhimThuong::Test()
{
	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			if (ghe[i][j] > 0)
				return 1;
		}
	}
	return 0;
}

bool RapPhimThuong::ViTriTrong(int i, int j)
{
	if (this->ghe[i][j] > 0)
		return 1;
	return 0;
}

RapPhimThuong& RapPhimThuong::operator=(const RapPhimThuong &r)
{
	for (int i = 0; i < this->m; i++)
	{
		delete[] this->ghe[i];
	}
	delete[] this;

	this->m = r.m ;
	this->n = r.n;
	this->ghe = new int*[this->m];

	for (int i = 0; i < this->m; i++)
	{
		this->ghe[i] = new int[this->n];
	}
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
		{
			this->ghe[i][j] = r.ghe[i][j];
		}
	return *this;
}


void RapPhimThuong::GheTrungTam()
{
	int temp = this->m / 2;
	if (temp % 2 != 0)
		cout << "Hang trung tam la: " << temp + 1 << endl;
	else
	{
		cout << "Hang trung tam la: " << temp << " va " << temp + 1 << endl;
	}
}



void RapPhimThuong::Gia(int i, int j)
{
	int hang = this->m / 2;
	int temp;
	int temp2 = 0;
	if (hang % 2 != 0)
		temp = hang + 1;
	else
	{
		temp2 = this->m / 2;
	}
	int gia = this->gia;
	if (i == temp)
		cout << "Gia ve la: " << gia << endl;
	else if (i == temp2)
		cout << "Gia ve la: " << gia << endl;
	else if (i == temp2 + 1)
		cout << "Gia ve la: " << gia << endl;
	else
	{
		cout << "Gia ve la: " << gia - 3000 << endl;
	}
}

void RapPhimThuong::DatVe(int i, int j)
{
	int so;
	if (this->ghe[i][j] == 0)
	{
		cout << "Nhap stt muon dat: ";
		cin >> so;
		cout << endl << "Dat ghe thanh cong" << endl;
	}
	else
	{
		cout << "Ghe da co nguoi dat. Vui long chon ghe khac";
	}
}

long int RapPhimThuong::TinhTongTien()
{
	long int sum = 0;
	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			sum += this->ghe[i][j];
	return sum;
}
void RapCaoCap::Gia(int i, int j)
{	
	cout << "Hom nay la thu may ? ";
	cin >> this->thu;
	cout << endl;
	int hang = this->m / 2;
	int temp;
	int temp2 = 0;
	int temp3 = 0;
	if (hang % 2 != 0)
		temp = hang + 1;
	else
	{
		temp2 = this->m / 2;
		//temp3 = this->m / 2;
	}
	float gia = this->gia;
	if (i == temp)
		cout << "Gia ve la: " << gia << endl;
	else if (i == temp && this->thu == 5)
		cout << "Gia ve la: " << gia - (gia * 0.2) << endl;
	else if (i == temp2)
		cout << "Gia ve la: " << gia << endl;
	//else if (i == temp3 && this->thu = 5)
		//cout << "Gia ve la: " << gia - (gia * 0.2) << endl;
	else if (i == temp2 + 1)
		cout << "Gia ve la: " << gia << endl;
	//else if (i == temp3 + 1 && this->thu = 5)
		//cout << "Gia ve la: " << gia - (gia * 0.2) << endl;
	else
	{
		cout << "Gia ve la: " << gia - 3000 << endl;
	}
}

RapPhimThuong::~RapPhimThuong()
{
	for (int i = 0; i < this->n; i++)
	{
		delete[] this->ghe[i];
	}
	delete[] this;
}