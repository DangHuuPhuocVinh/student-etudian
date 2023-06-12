create database 1752052_Transaction2
--Ex1
-- Tạo bảng Lớp
create table LOP (
	MaLop varchar(6) PRIMARY KEY not null,
	MaLopTruong varchar(3),
	SiSo int
);

-- Tạo bảng Sinh viên
create table SINH_VIEN (
	MSSV varchar(8) PRIMARY KEY not null,
	MaLop varchar(6),
	Hoten nvarchar(50),
	NgaySinh Date,
	GioiTinh nvarchar(5),
	TinhTrang bit default '0',
	constraint fk1_MaLop_MaLop
	foreign key (MaLop)
	references LOP(MaLop)
);

-- Tạo bảng Môn học
create table MON_HOC (
	MaMH varchar(4) PRIMARY KEY,
	SoTinChi TINYINT,
	NamHoc date,
	HocKi varchar(2),
	SLDangKyConLai int
);

-- Tạo bảng Đăng ký
create table DANG_KY (
	MSSV varchar(8) not null,
	MaMH varchar(4) not null,
	ngayDK Date,
	primary key (MSSV, MaMH), --tạo 2 khóa chính cho 1 bảng
	constraint fk1_MSSV_MSSV
	foreign key (MSSV)
	references SINH_VIEN(MSSV),
	constraint fk2_MaMH_MaMH
	foreign key (MaMH)
	references MON_HOC(MaMH)
);

-- Ex2.1

-- Tạo store procedure spDangKyMonHoc
create proc spDangKyMonHoc (
	@mssv varchar(8),
	@maMH varchar(4), 
	@ngayDK Date
	)
as
begin
	begin tran

		declare @tinhtrang bit = (select TinhTrang from SINH_VIEN WHERE MSSV = @mssv) -- Lấy tình trạng sinh viên trong bảng SINH_VIEN
		declare @soluong int = (select SLDangKyConLai from MON_HOC WHERE MaMH = @maMH) -- Lấy số lượng còn lại trong bảng MON_HOC

		if not exists (select MSSV from SINH_VIEN where MSSV = @mssv) -- Nếu không tồn tại MSSV trong bảng SINH_VIEN
		begin
			print N'MSSV này không tồn tại'  -- In ra màn hình 
			rollback
		end
		
		if not exists (select MaMH from MON_HOC where MaMH = @maMH) -- Nếu không tồn tại mã môn học tương ứng trong bảng MON_HOC
		begin
			print N'Môn học này không tồn tại' -- In ra màn hình
			rollback
		end
		
		if @tinhtrang = 0 -- Nếu tình trạng sinh viên là 0 tức là sinh viên đã thôi học
		begin
			raiserror (N'Sinh viên này không thể đăng kí môn vì đã thôi học', 10, 1)
			rollback
		end
		
		if @soluong = 45 -- Nếu số lượng sinh viên đăng kí đã đủ 45 sinh viên
		begin
			raiserror (N'Môn học này đã đủ sĩ số', 10, 1) 
			rollback
		end
		 
		
			insert into DANG_KY VALUES (@mssv, @maMH, @ngayDK) -- Ghi danh môn học
			update MON_HOC
			set SLDangKyConLai += 1 -- Cập nhật số lượng đăng kí cho bảng MON_HOC
			where MaMH = @maMH
		
	commit tran
end
go

exec spDangKyMonHoc '17547896', 'ABC', '2020-4-1'
go

-- Tạo store procedure spXemDanhSachSinhVienDangKy
create proc spXemDanhSachSinhVienDangKy
as
begin tran
	select * from DANG_KY, MON_HOC
commit
go

exec spXemDanhSachSinhVienDangKy

