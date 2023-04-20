-- Nguyen Hoang Long - 1752028
-- Dang Huu Phuoc Vinh -1752052
-- waitfor delay '00:00:10'

create database HTNHThuongViet
go
use HTNHThuongViet
go

-- CREATE TABLE
create table ChiNhanh(
	IDChiNhanh varchar(8) not null,
	IDThucDon varchar(8) not null,	
	DiaChi nvarchar(40) not null,
	TenChiNhanh nvarchar(40),
	DienThoai nvarchar(10)

	primary key(IDChiNhanh)
)
go

create table ThucDon(
	IDThucDon varchar(8) not null,
	IDMonAn int	not null,
	IDChiNhanh varchar(8),
	SoLuongConLai int,

	primary key(IDThucDon, IDMonAn)
)
go

create table MonAn(
	IDMonAn int primary key not null,
	TenMon nvarchar(50) not null,
	LoaiMon nvarchar(20),
	Gia bigint
)
go

create table ThanhVien(
	IDThanhVien int IDENTITY(1111,1111) primary key not null,
	TenThanhVien nvarchar(40),
	HangThanhVien varchar(7),
	NgaySinh date,
	CMND varchar(12) not null,
	DiaChi nvarchar(40),
	ChiNhanhDangKy varchar(8) not null,
	DienThoai nvarchar(10),
	DiemTichLuy bigint

)
go

create table KhachHang (
	IDKhachHang bigint  IDENTITY(100000,1) primary key,
	TenKH nvarchar(40),
	SDTKH varchar(11)
)

create table DonHang(
	IDDonHang int IDENTITY(10,1) primary key not null,
	IDThanhVien int,
	LoaiDatHang nvarchar(15) not null,

	TenNguoiNhan nvarchar(40),
	ChiNhanhDatHang varchar(8),
	DiaChiGiaoHang nvarchar(40) not null,
	SoDienThoaiNhan nvarchar(10) not null,
	PhuongThucThanhToan nvarchar(20),
	MaGiamGia varchar(8),
	
	TrangThaiDonHang nvarchar(14),
	TimeGiaoHang date,
	PhiGiaoHang bigint,

	Tong bigint
)
go


create table GioHang(
	IDGioHang int not null,
	IDMonAn int not null,
	SoLuong int default '1',
	DonGia bigint,
	IDDonHang int

	primary key(IDGioHang, IDMonAn)
)

--=======================

ALTER TABLE ThucDon
ADD FOREIGN KEY (IDMonAn) references MonAn(IDMonAn)
go

ALTER TABLE ThucDon
ADD FOREIGN KEY (IDChiNhanh) references ChiNhanh(IDChiNhanh)
go

ALTER TABLE DonHang
ADD FOREIGN KEY (ChiNhanhDatHang) references ChiNhanh(IDChiNhanh)
go

ALTER TABLE DonHang
ADD FOREIGN KEY (IDThanhVien) references ThanhVien(IDThanhVien)
go

ALTER TABLE GioHang 
ADD FOREIGN KEY (IDMonAn) references MonAn(IDMonAn)
go

ALTER TABLE GioHang
ADD FOREIGN KEY (IDDonHang) references DonHang(IDDonHang)
go

--=================================================================================
--INSERT DATA
insert into MonAn(IDMonAn, TenMon, LoaiMon, Gia)
values(111, N'Phở bò', N'Món Nước', 25000)
go
insert into MonAn(IDMonAn, TenMon, LoaiMon, Gia)
values(222, N'Bún Bò Huế', N'Món Nước', 28000)
go
insert into MonAn(IDMonAn, TenMon, LoaiMon, Gia)
values(333, N'Nem nướng', N'Nem', 10000)
go
insert into MonAn(IDMonAn, TenMon, LoaiMon, Gia)
values(444, N'Cơm tấm', N'Cơm', 25000)
go
insert into MonAn(IDMonAn, TenMon, LoaiMon, Gia)
values(555, N'Cơm gà chiên nước mắm', N'Cơm', 30000)
go
insert into MonAn(IDMonAn, TenMon, LoaiMon, Gia)
values(666, N'Bánh bông lan kem', N'Tráng miệng', 50000)
go

--=================================================================================

insert into ChiNhanh(IDChiNhanh, IDThucDon, DiaChi, TenChiNhanh, DienThoai)
values ('01020304', '001', N'363 Nguyễn Thiện Thuật', N'Nguyễn Thiện Thuật', '0805251458')
go
insert into ChiNhanh(IDChiNhanh, IDThucDon, DiaChi, TenChiNhanh, DienThoai)
values ('01025241', '002', N'33 Trần Hưng Đạo', N'Trần Hưng Đạo', '0807745458')
go
insert into ChiNhanh(IDChiNhanh, IDThucDon, DiaChi, TenChiNhanh, DienThoai)
values ('77720304', '003', N'358 Phạm Viết Chánh', N'Phạm Viết Chánh', '0806255458')
go
insert into ChiNhanh(IDChiNhanh, IDThucDon, DiaChi, TenChiNhanh, DienThoai)
values ('08044475', '004', N'174 Hùng Vương', N'Hùng Vương', '0804456988')
go

--=================================================================================
--=================================================================================

--=================================================================================

insert into ThucDon(IDThucDon,IDChiNhanh, IDMonAn, SoLuongConLai)
values('001', '01020304', '111', 30)
go
insert into ThucDon(IDThucDon,IDChiNhanh, IDMonAn, SoLuongConLai)
values('001', '01020304', '222', 10)
go
insert into ThucDon(IDThucDon,IDChiNhanh, IDMonAn, SoLuongConLai)
values('001', '01020304', '333', 20)
go


insert into ThucDon(IDThucDon,IDChiNhanh,IDMonAn, SoLuongConLai)
values('002', '01025241', '444', 100)
go
insert into ThucDon(IDThucDon, IDChiNhanh, IDMonAn, SoLuongConLai)
values('002', '01025241', '555', 40)
go
insert into ThucDon(IDThucDon, IDChiNhanh, IDMonAn, SoLuongConLai)
values('002', '01025241', '666', 50)
go

insert into ThucDon(IDThucDon, IDChiNhanh, IDMonAn, SoLuongConLai)
values('003', '77720304', '444', 100)
go
insert into ThucDon(IDThucDon, IDChiNhanh, IDMonAn, SoLuongConLai)
values('003', '77720304', '555', 40)
go
insert into ThucDon(IDThucDon, IDChiNhanh, IDMonAn, SoLuongConLai)
values('003', '77720304', '666', 50)
go

insert into ThucDon(IDThucDon, IDChiNhanh, IDMonAn, SoLuongConLai)
values('004', '08044475', '444', 100)
go
insert into ThucDon(IDThucDon, IDChiNhanh, IDMonAn, SoLuongConLai)
values('004', '08044475', '555', 40)
go
insert into ThucDon(IDThucDon, IDChiNhanh, IDMonAn, SoLuongConLai)
values('004', '08044475', '666', 50)
go


--=================================================================================
--=================================================================================

insert into ThanhVien(TenThanhVien, HangThanhVien, NgaySinh, CMND, DiaChi, ChiNhanhDangKy, DienThoai, DiemTichLuy)
values(N'Nguyễn Văn A', 'Gold', null, '079001225445', '77720304', '01025241', '0905874233', 5000)
go
insert into ThanhVien(TenThanhVien, HangThanhVien, NgaySinh, CMND, DiaChi, ChiNhanhDangKy, DienThoai, DiemTichLuy)
values(N'Trần Văn B', 'Diamond', null, '079004445776', '08044475', '77720304', '0909004789', 100000)
go

--=================================================================================
--=================================================================================

insert into DonHang(IDThanhVien, LoaiDatHang, TenNguoiNhan, ChiNhanhDatHang, DiaChiGiaoHang, SoDienThoaiNhan, PhuongThucThanhToan, MaGiamGia, TrangThaiDonHang, TimeGiaoHang, PhiGiaoHang, Tong)
values(1111, N'online', N'Nguyễn Văn A', '01025241', N'33 Phạm Ngũ Lão', '0805142535', 'COD', null, N'Tiếp nhận', '12/12/2020 01:05:00', 50000, 90000)
go

insert into DonHang(IDThanhVien, LoaiDatHang, TenNguoiNhan, ChiNhanhDatHang, DiaChiGiaoHang, SoDienThoaiNhan, PhuongThucThanhToan, MaGiamGia, TrangThaiDonHang, TimeGiaoHang, PhiGiaoHang, Tong)
values(null, N'điện thoại', N'Dương Văn D', '01025241', N'36 Trường Sa', '0905447123', 'COD', null, N'Tiếp nhận', '10/12/2020 18:05:00', 30000, 70000)
go

--==================================================================================
--==================================================================================
insert into GioHang(IDGioHang, IDMonAn, SoLuong, DonGia, IDDonHang)
values (1000, 111, 5, 125000, 10)
go

insert into GioHang(IDGioHang, IDMonAn, SoLuong, DonGia, IDDonHang)
values (1000, 222, 5, 128000, 10)
go

insert into GioHang(IDGioHang, IDMonAn, SoLuong, DonGia, IDDonHang)
values (1001, 111, 5, 125000, 11)
go

insert into GioHang(IDGioHang, IDMonAn, SoLuong, DonGia, IDDonHang)
values (1001, 222, 5, 128000, 11)
go


 
