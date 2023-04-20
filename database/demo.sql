sp_addrole 'WinGuest'

grant create procedure, create table to WinGuest
use demo
go
 sp_addLogin 'LoginA1', 'A1'
 sp_addLogin 'LoginA2', 'A2'
 go

create User userA1 for login LoginA1
create User userA2 for login LoginA2
go

create table SINHVIEN(
	MSSV varchar(8) primary key,
	HoTen nvarchar(25), 
);

Create table BO_MON(	
	MaBM varchar(8) primary key,
	MaKhoa varchar(8),
);

sp_addrole 'Role1'
grant select , insert on SINHVIEN to Role1;
grant select , insert on BO_MON to Role1;

sp_addrolemember 'Role1' ,'userA1'
sp_addrolemember 'Role1' ,'userA2'
go

deny insert to userA2