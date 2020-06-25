#include"Reader.h"

int main()
{
	DocGiaThuong A; 
	A.NhapDocGia();
	A.XuatDocGia();

	DocGiaVIP B;
	B.NhapDocGia();
	B.XuatDocGia();
	cout << "So tien: " << B.SoTien();

	_getch();
	return 0;

}