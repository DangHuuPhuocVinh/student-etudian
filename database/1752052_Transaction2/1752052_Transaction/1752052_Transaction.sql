create table KhachHang(
makh varchar(8) primary key not null,
hoten nvarchar(40),
ngaysinh datetime,
diachi nvarchar(40)
)

create table TaiKhoanATM(
soTaiKhoan varchar(8) primary key not null,
makh varchar(8),
sodu varchar(40),
ngayLap datetime,
ngayHetHan datetime,
uid varchar(8) not null,
pwd varchar(8) not null,
constraint fk1_makh_makh
foreign key (makh)
references KhachHang(makh)
)

create table LichSuGiaoDich_RutTien(
MaGD varchar(8) primary key not null,
SoTKRut varchar(8),
SoTien varchar(20),
ngayGD datetime,
constraint fk1_SoTKRut_soTaiKhoan
foreign key (SoTKRut)
references TaiKhoanATM (soTaiKhoan)
)

create table LichSuGiaoDich_ChuyenTien(
MaGD varchar(8) primary key not null,
SoTKChuyen varchar(8),
SoTKNhan varchar(8),
SoTien varchar (20),
ngayGD datetime,
constraint fk1_SoTKChuyen_soTaiKhoan
foreign key (SoTKChuyen)
references TaiKhoanATM (soTaiKhoan),
constraint fk2_SoTKNhan_soTaiKhoan
foreign key (SoTKNhan)
references TaiKhoanATM (soTaiKhoan)
)

insert into KhachHang
values ('01254758',N'Nguyễn Văn A',null,N'5b Trần Hưng Đạo');
insert into KhachHang
values ('05858558',N'Nguyễn Thị B',null,N'5a Trần Hưng Đạo');
insert into KhachHang
values ('00014580',N'Trần Văn A',null,N'66 Trần Huy Liệu');
insert into KhachHang
values ('08574625',N'Triệu Thành C',null,N'85C An Dương Vương');

insert into TaiKhoanATM 
values ('01020102','01254758','2000000','2007/7/2','2021/3/2','01254758','12345678');
insert into TaiKhoanATM 
values ('08547869','05858558','10000000','2004/5/5','2009/3/6','05858558','87654321');
insert into TaiKhoanATM 
values ('09854725','00014580','20000000','2009/7/2','2022/6/5','00014580','12345678');

insert into LichSuGiaoDich_RutTien 
values ('04521456','01020102','2000000','2010/7/7');
insert into LichSuGiaoDich_RutTien 
values ('08547692','08547869','5000000','2015/10/5');
insert into LichSuGiaoDich_RutTien 
values ('08545522','08547869','5000000','2020/4/8');

insert into LichSuGiaoDich_ChuyenTien 
values ('00251438','01020102','08547869','1000000','2014/11/5');
insert into LichSuGiaoDich_ChuyenTien 
values ('00247858','09854725','08547869','1000000','2011/2/25');
insert into LichSuGiaoDich_ChuyenTien 
values ('01425876','01020102','09854725','500000','2017/12/28');
insert into LichSuGiaoDich_ChuyenTien 
values ('01425874','01020102','09854725','500000','2020/4/8');

select * from LichSuGiaoDich_ChuyenTien



go

--1
create procedure List_Of_Deal_Day (
	 @ngayGD datetime
)
as --, LichSuGiaoDich_ChuyenTien.MaGD, LichSuGiaoDich_RutTien.MaGD
begin
	select DISTINCT KhachHang.hoten
	from LichSuGiaoDich_ChuyenTien, TaiKhoanATM, KhachHang, LichSuGiaoDich_RutTien
	where (LichSuGiaoDich_ChuyenTien.ngayGD = @ngayGD 
	AND TaiKhoanATM.soTaiKhoan = LichSuGiaoDich_ChuyenTien.SoTKChuyen
	AND TaiKhoanATM.makh = KhachHang.makh) 
	OR (LichSuGiaoDich_RutTien.ngayGD = @ngayGD
	AND LichSuGiaoDich_RutTien.SoTKRut = TaiKhoanATM.soTaiKhoan
	AND TaiKhoanATM.makh = KhachHang.makh)
end
go

exec List_Of_Deal_Day '2004-12-20'
exec List_Of_Deal_Day '2010-7-7'

go

--2
create proc Expiration_Date_Of_Account
as
begin
	select *
	from TaiKhoanATM
	where ngayHetHan < GETDATE()
end
go

exec Expiration_Date_Of_Account

go

--3
create proc List_OF_Withdrawal_Today
as
begin
	select *
	from LichSuGiaoDich_RutTien
	where DAY(ngayGD) = DAY(GETDATE())
	AND MONTH(ngayGD) = MONTH(GETDATE())
	AND YEAR(ngayGD) = YEAR(GETDATE())
end
go

exec List_Of_Withdrawal_Today    
   
go

--4
create proc List_Of_Transfer_Today
as
begin
	select *
	from LichSuGiaoDich_ChuyenTien
	where DAY(ngayGD) = DAY(GETDATE())
	AND MONTH(ngayGD) = MONTH(GETDATE())
	AND YEAR(ngayGD) = YEAR(GETDATE())
end
go

exec List_Of_Transfer_Today

go

--5
create proc All_Deal_Of_Account(
	@ngayGD datetime
)
as 
begin
	select DISTINCT KhachHang.hoten,LichSuGiaoDich_ChuyenTien.MaGD, LichSuGiaoDich_RutTien.MaGD
	from LichSuGiaoDich_ChuyenTien, TaiKhoanATM, KhachHang, LichSuGiaoDich_RutTien
	where (LichSuGiaoDich_ChuyenTien.ngayGD = @ngayGD 
	AND TaiKhoanATM.soTaiKhoan = LichSuGiaoDich_ChuyenTien.SoTKChuyen
	AND TaiKhoanATM.makh = KhachHang.makh) 
	OR (LichSuGiaoDich_RutTien.ngayGD = @ngayGD
	AND LichSuGiaoDich_RutTien.SoTKRut = TaiKhoanATM.soTaiKhoan
	AND TaiKhoanATM.makh = KhachHang.makh)
end
go

exec All_Deal_Of_Account '2015/10/5'

--6
alter proc Information_Of_Account(
	@taikhoan varchar(8)
	)
as
begin 
	select *
	from TaiKhoanATM, KhachHang
	where KhachHang.makh = TaiKhoanATM.makh AND TaiKhoanATM.soTaiKhoan = @taikhoan
end
go

exec Information_Of_Account '01020102'

--7
create proc Surplus_Of_Account(
	@taikhoan varchar(8)
	)
as
begin 
	select TaiKhoanATM.soTaiKhoan, TaiKhoanATM.sodu
	from TaiKhoanATM
	where TaiKhoanATM.soTaiKhoan = @taikhoan
end
go

exec Surplus_Of_Account '01020102'

--8
create proc Add_Withdrawal_To_Account(
 @taikhoan varchar(8),
 @sotien varchar(20),
 @ngayGD datetime,
 @maGD varchar(8)
 )
 as
 begin 
	insert into LichSuGiaoDich_RutTien(MaGD, SoTKRut, SoTien, ngayGD)
	values (@maGD,@taikhoan, @sotien, @ngayGD)
end
go

exec Add_Withdrawal_To_Account @maGD = '02505201',@taikhoan = '01020102',@sotien = '600000',@ngayGD = '2020/2/2'

select * from LichSuGiaoDich_RutTien

--9
create proc Add_Tranfer_To_Account(
	@SoTKChuyen varchar(8),
	@SoTKNhan varchar(8),
	@sotien varchar(20),
	@ngayGD datetime,
	@maGD varchar(8)
)
as
begin
	begin tran
		declare @maGD = '00000000'
		
		while exists(select * from LichSuGiaoDich_ChuyenTien where MaGD = @maGD)
			set @maGD = @maGD + 1
			
		insert into LichSuGiaoDich_ChuyenTien values (@maGD, @SoTKChuyen, @SoTKNhan, @sotien, GETDATE())
		
		update TaiKhoanATM set sodu = sodu - @sotien where soTaiKhoan = @SoTKChuyen
		
		if((select sodu from TaiKhoanATM where soTaiKhoan = @SoTKChuyen) < 0)
		begin
			print('Tai khoan khong du tien.')
			rollback
			return
		end
		
		update TaiKhoanATM set sodu = sodu + @sotien where soTaiKhoan = @SoTKNhan	
	commit
end
go

exec Add_Tranfer_To_Account @maGD = '05214796', @SoTKChuyen = '01020102', @SoTKNhan = '08547869', @sotien = '15000000', @ngayGD = '2020/3/2'
select * from LichSuGiaoDich_ChuyenTien


--10

create proc Add_New
@tk int, @sotien int
as
begin
	begin tran
		SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
		if not exists (select soTaiKhoan from TaiKhoanATM where soTaiKhoan = @tk)
		begin
			print 'SoTK khong ton tai'
			rollback
			return
		end
		
		declare @sodu int = (select sodu from TaiKhoanATM where soTaiKhoan = @tk)
		update TaiKhoanATM set sodu = @sodu - @sotien where soTaiKhoan = @tk
		waitfor delay '00:00:10'
		
		if((@sodu - @sotien) < 0)
		begin
			print('Tai khoan khong du tien.')
			rollback
			return
		end
		
		declare @maGd int = 0

		while exists (select * from LichSuGiaoDich_RutTien as RT 
					  where RT.MaGD = @maGd)
			set @maGd = @maGd + 1
			
		insert into LichSuGiaoDich_RutTien values(@maGd, @tk, @sotien, GETDATE())
	commit 				
end
go

--them 1 account
create proc Add_New_Account
(
	@makh varchar(8),
	@hoten nvarchar(40),
	@ngaysinh datetime,
	@diachi nvarchar(40)
	)
	as
	begin 
		begin tran
			if exists (select * from KhachHang where @makh = makh and @hoten = hoten)
			begin
			print 'SoTK nay da ton tai'
			rollback
			return
			end
		insert into KhachHang(makh, hoten, ngaysinh, diachi)
			values (@makh, @hoten, @ngaysinh, @diachi)
	commit
	end

create proc Update_Account
(
	@soTK varchar(8),
	@makh varchar(8),
	@sodu varchar(40),
	@ngayLap datetime,
	@ngayHetHan datetime,
	@uid varchar(8),
	@pwd varchar(8),
	)
	as
	begin 
		begin tran
			if not exists (select * from TaiKhoanATM where @soTK = soTaiKhoan and @makh = makh)
			begin
			print 'SoTK khong ton tai'
			rollback
			return
			end
		declare @soTK varchar(8) = (select soTaiKhoan from TaiKhoanATM where @soTK = soTaiKhoan)
		update TaiKhoanATM set sodu = @sodu, ngayLap = @ngayLap, ngayHetHan = @ngayHetHan, uid = @uid, pwd = @pwd
	commit
	end
go
--xoa 1 giao dich rut tien

create proc Delete1
(
	@MaGD varchar(8),
	@SoTKRut varchar(8),
	@SoTien varchar(20),
	@ngayGD datetime
	)
	as
	begin 
		begin tran
			if not exists (select * from LichSuGiaoDich_RutTien where @MaGD = MaGD)
			begin
			print 'Giao dich khong ton tai'
			rollback
			return
			end
		delete from LichSuGiaoDich_RutTien where @MaGD = MaGD and @SoTKRut = SoTKRut
	commit
	end

go
-- xoa 1 giao dich chuyen tien
create proc Delete2
(
	@MaGD varchar(8),
	@SoTKRut varchar(8),
	@SoTien varchar(20),
	@ngayGD datetime
	)
	as
	begin 
		begin tran
			if not exists (select * from LichSuGiaoDich_ChuyenTien where @MaGD = MaGD)
			begin
			print 'Giao dich khong ton tai'
			rollback
			return
			end
		delete from LichSuGiaoDich_ChuyenTien where @MaGD = MaGD 
	commit
	end
