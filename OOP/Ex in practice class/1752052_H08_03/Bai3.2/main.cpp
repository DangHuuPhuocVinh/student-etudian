#include"Reader.h"

int main()
{
	DocGiaThuong A("A", 213123, 5);
	//A.NhapDocGia();
	A.XuatDocGia();

	DocGiaVIP B;
	//B.NhapDocGia();
	B.XuatDocGia();
	cout << "So tien: " << B.SoTien();
	
	_getch();
	return 0;

}