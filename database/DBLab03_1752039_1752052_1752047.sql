--  Đặng Hữu Phước Vinh - 1752052
-- Mai Trọng Nhân - 1752039
-- Lư Mạnh Toàn - 1752047

CREATE DATABASE HealthOneMedical
GO

USE HealthOneMedical
GO

CREATE TABLE DOCTOR
(
	Doctor_ID INT NOT NULL,
	Name NVARCHAR(30),
	Address NVARCHAR(60),
	Phone INT,
	Specialization NVARCHAR(30), -- chuyên khoa của Doctor
	PRIMARY KEY(Doctor_ID)
)
GO


CREATE TABLE PATIENT
(
	Patient_ID INT NOT NULL,
	Name NVARCHAR(30),
	Address NVARCHAR(60),
	Phone INT,
	Email NVARCHAR(20),
	Insurance_ID INT, -- mã số bảo hiểm
	Primary_Doctor INT, -- bác sĩ của bệnh nhân
	PRIMARY KEY(Patient_ID)
)

CREATE TABLE PRESCRIPTION -- đơn thuốc
(
	RX_ID INT NOT NULL, -- mã đơn thuốc
	Date_Prescribed DATETIME,
	Dosage NVARCHAR(30), -- liều lượng thuốc
	Duration NVARCHAR(30), -- thời hạn sử dụng 
	Refillable NVARCHAR(30), -- thời gian tái khám
	Number_of_Refills INT, -- số lần tái khám
	Comments NVARCHAR(30), -- yêu cầu
	Reason NVARCHAR(30), -- chuẩn đoán
	Patient_ID INT,
	Doctor_ID INT,
	Drug_ID INT,
	PRIMARY KEY(RX_ID)
)
GO

CREATE TABLE HOSPITAL
(
	Hospital_ID INT,
	Name NVARCHAR(30),
	Address NVARCHAR(60),
	Phone INT,
	PRIMARY KEY(Hospital_ID)
)

CREATE TABLE OFFICE_VISITS -- nhật ký khám bệnh
(
	PatientID INT NOT NULL,
	DoctorID INT NOT NULL,
	Date_Of_Visit DATETIME NOT NULL, -- ngày khám
	-- các bước khám bệnh
	Symptoms NVARCHAR(50), -- triệu chứng bệnh
	Initial_Diagnosis NVARCHAR(30), -- chuẩn đoán ban đầu
	Diagnosis_Status NVARCHAR(30), -- tình trạng chuẩn đoán
	Blood_Pressure NVARCHAR(30), -- kết quả đo huyết áp
	Height INT, -- chiều cao của bệnh nhân
	Weight INT, -- cân nặng của bệnh nhân
	Diagnosis NVARCHAR(50), -- kết quả chuẩn đoán
	PRIMARY KEY(PatientID, DoctorID, Date_Of_Visit)
)
GO

CREATE TABLE DRUG
(
	DrugID INT NOT NULL,
	DrugName NVARCHAR(30), -- tên thuốc
	SideEffects NVARCHAR(30), -- tác dụng phụ của thuốc
	Benefits NVARCHAR(30), -- tác dụng của thuốc
	PRIMARY KEY(DrugID)
)
GO

CREATE TABLE INSURANCES
(
	InsuranceCompanyID INT NOT NULL,
	InsuranceCompany NVARCHAR(30), -- tên công ty bảo hiểm
	Phone INT,
	PRIMARY KEY(InsuranceCompanyID)
)

CREATE TABLE HOSPITAL_AFILITATION
(
	Doctor_ID INT NOT NULL,
	Hospital_ID INT NOT NULL,
	Date_Of_Affilation DATETIME, -- ngày vào làm việc
	PRIMARY KEY(Doctor_ID, Hospital_ID)
)

CREATE TABLE PRIMARY_DOCTOR_HISTORIES
(
	Patient_ID INT NOT NULL,
	Doctor_ID INT NOT NULL,
	Start_Date DATETIME NOT NULL,
	End_Date DATETIME,
	Reason_For_Leaving NVARCHAR(50),
	PRIMARY KEY(Patient_ID, Doctor_ID, Start_Date)
)

ALTER TABLE dbo.PATIENT ADD CONSTRAINT FK_PATIENT_INSURANCES FOREIGN KEY(Insurance_ID)
REFERENCES dbo.INSURANCES(InsuranceCompanyID)

ALTER TABLE dbo.PATIENT ADD CONSTRAINT FK_PATIENT_DOCTOR FOREIGN KEY(Primary_Doctor)
REFERENCES dbo.DOCTOR(Doctor_ID)

ALTER TABLE dbo.HOSPITAL_AFILITATION ADD CONSTRAINT FK_HOSPITAL_AFILITATION_DOCTOR FOREIGN KEY(Doctor_ID)
REFERENCES dbo.DOCTOR(Doctor_ID)

ALTER TABLE dbo.HOSPITAL_AFILITATION ADD CONSTRAINT FK_HOSPITAL_AFILITATION_HOSPITAL FOREIGN KEY(Hospital_ID)
REFERENCES dbo.HOSPITAL(Hospital_ID)

ALTER TABLE dbo.OFFICE_VISITS ADD CONSTRAINT FK_OFFICE_VISITS_PATIENT FOREIGN KEY(PatientID)
REFERENCES dbo.PATIENT(Patient_ID)

ALTER TABLE dbo.OFFICE_VISITS ADD CONSTRAINT FK_OFFICE_VISITS_DOCTOR FOREIGN KEY(DoctorID)
REFERENCES dbo.DOCTOR(Doctor_ID)

ALTER TABLE dbo.PRESCRIPTION ADD CONSTRAINT FK_PRESCRIPTION_PATIENT FOREIGN KEY(Patient_ID)
REFERENCES dbo.PATIENT(Patient_ID)

ALTER TABLE dbo.PRESCRIPTION ADD CONSTRAINT FK_PRESCRIPTION_DOCTOR FOREIGN KEY(Doctor_ID)
REFERENCES dbo.DOCTOR(Doctor_ID)

ALTER TABLE dbo.PRESCRIPTION ADD CONSTRAINT FK_PRESCRIPTION_DRUG FOREIGN KEY(Drug_ID)
REFERENCES dbo.DRUG(DrugID)

ALTER TABLE dbo.PRIMARY_DOCTOR_HISTORIES ADD CONSTRAINT FK_PRIMARY_DOCTOR_HISTORIES_PATIENT FOREIGN KEY(Patient_ID)
REFERENCES dbo.PATIENT(Patient_ID)

ALTER TABLE dbo.PRIMARY_DOCTOR_HISTORIES ADD CONSTRAINT FK_PRIMARY_DOCTOR_HISTORIES_DOCTOR FOREIGN KEY(Doctor_ID)
REFERENCES dbo.DOCTOR(Doctor_ID)