/* Đặng Hữu Phước Vinh 1752052 */


/* Create table and make the keys */
CREATE TABLE EMPLOYEES(
EMP_ID varchar(5) PRIMARY KEY NOT NULL,
EMPNAME nvarchar(40),
ADDR nvarchar(50),
COUNTRY nvarchar(30),
PHONE varchar(10),
SEX nvarchar(3),
SALARY int,
HIREDATE datetime,
EMAIL varchar(15),
JOBID varchar(5),
MANAGER_ID varchar(5),
CONSTRAINT fk1_jobid_jobid
FOREIGN KEY (JOBID)
REFERENCES JOBS (JOB_ID),
CONSTRAINT fk2_managerid_empid
FOREIGN KEY (MANAGER_ID)
REFERENCES EMPLOYEES (EMP_ID)
)

CREATE TABLE DEPARTMENTS(
DEPT_ID varchar(5) PRIMARY KEY NOT NULL,
DEPTNAME nvarchar(30),
DEPT_MNG varchar(5),
LOCATION_ID varchar(5),
CONSTRAINT fk1_deptmng_empid
FOREIGN KEY (DEPT_MNG)
REFERENCES EMPLOYEES (EMP_ID),
CONSTRAINT fk2_locid_locid
FOREIGN KEY (LOCATION_ID)
REFERENCES LOCATIONS (LOC_ID)
)

CREATE TABLE LOCATIONS(
LOC_ID varchar(5) PRIMARY KEY NOT NULL,
STR_ADDR nvarchar(20),
POSTALCODE varchar(10),
CITY nvarchar(20),
STATE_PROVINCE nvarchar(20),
COUNTRY varchar(15)
)

CREATE TABLE JOBS(
JOB_ID varchar(5) PRIMARY KEY NOT NULL,
JOBTITLES nvarchar(30),
MINSALARY int,
MAXSALARY int
)

CREATE TABLE JOBS_HISTORY(
EMPID varchar(5) PRIMARY KEY NOT NULL, 
START_DATE datetime  NOT NULL,
END_DATE datetime,
JOB_ID varchar(5),
DEPT_ID varchar(5),
CONSTRAINT fk1_empid_empid
FOREIGN KEY (EMPID)
REFERENCES EMPLOYEES (EMP_ID),
CONSTRAINT fk2_jobid_jobid
FOREIGN KEY (JOB_ID)
REFERENCES JOBS (JOB_ID),
CONSTRAINT fk3_deptid_deptid
FOREIGN KEY (DEPT_ID)
REFERENCES DEPARTMENTS (DEPT_ID)
)

/* Input data */
INSERT INTO JOBS
VALUES ('001',N'Lập trình viên','8000000','20000000');
INSERT INTO JOBS
VALUES ('002',N'Thiết kế dữ liệu','7000000','18000000');
INSERT INTO JOBS
VALUES ('003','Data scientist','15000000','30000000');
INSERT INTO JOBS
VALUES ('004','PM','25000000','40000000');
INSERT INTO JOBS
VALUES ('005','QA','24000000','38000000')

INSERT INTO LOCATIONS
VALUES ('001',N'Trần Hưng Đạo Q1',null,N'Hồ Chí Minh',N'Hồ Chí Minh','VietNam')
INSERT INTO LOCATIONS
VALUES ('002',N'Cao Thắng Q3',null,N'Hồ Chí Minh',N'Hồ Chí Minh','VietNam')
INSERT INTO LOCATIONS
VALUES ('003',N'Nguyễn Du Q1',null,N'Hồ Chí Minh',N'Hồ Chí Minh','VietNam')
INSERT INTO LOCATIONS
VALUES ('004',N'Nguyễn Văn Cừ Q5',null,N'Hồ Chí Minh',N'Hồ Chí Minh','VietNam')
INSERT INTO LOCATIONS
VALUES ('005',N'Đinh Tiên Hoàng Q1',null,N'Hồ Chí Minh',N'Hồ Chí Minh','VietNam')
INSERT INTO LOCATIONS
VALUES ('006','Aloha',null,'New York','New York','USA')

INSERT INTO EMPLOYEES
VALUES ('001','Harry',null,'USA','0909441366','Nam','20000000', null,'harry@gmail.com', '004','001')
INSERT INTO EMPLOYEES
VALUES ('002','Marry',null,'USA','0907421445',N'Nữ','20000000', null,'marry@gmail.com', '005','002')
INSERT INTO EMPLOYEES
VALUES ('003',N'Hoàng',null,N'Việt Nam','0908440366','Nam','18000000', null,null, '003','003')
INSERT INTO EMPLOYEES
VALUES ('004',N'Nguyệt',null,N'Việt Nam','0909441366',N'Nữ','20000000', null,'ng@gmail.com', '004','004')
INSERT INTO EMPLOYEES
VALUES ('005','Fabien',null,'France',null,'Nam','22000000', null,'fabien@gmail.fr', '004','005')
INSERT INTO EMPLOYEES
VALUES ('006','Mary',null,'England',null,N'Nữ','16000000', null,'mary@gmail.com', '003','006')
INSERT INTO EMPLOYEES
VALUES ('007','Corona',null,'England',null,N'Nữ','16000000', null,'coro@gmail.com', '003',null)
INSERT INTO EMPLOYEES
VALUES ('009','Marona',null,'Australia',null,N'Nữ','16000000', null,'mar@gmail.com', '003','009')
INSERT INTO EMPLOYEES
VALUES ('008','Kohashi',null,'Japan',null,'Nam','18000000', null,'kohsh@gmail.com', '003','008')
INSERT INTO EMPLOYEES
VALUES ('010','Mary',null,'Ireland',null,N'Nữ','18000000', null,'mari@gmail.com', '004','010')

INSERT INTO DEPARTMENTS
VALUES ('001','Ajax','002','004')
INSERT INTO DEPARTMENTS
VALUES ('002','Aloha','001','006')
INSERT INTO DEPARTMENTS
VALUES ('003','Bitexco','004','005')
INSERT INTO DEPARTMENTS
VALUES ('004',N'Hoa Hồng','003','001')
INSERT INTO DEPARTMENTS
VALUES ('005','New future','005','003')
INSERT INTO DEPARTMENTS
VALUES ('006','Coloc','001','006')

INSERT INTO JOBS_HISTORY
VALUES ('001','11/5/2010',null,'004','002')
INSERT INTO JOBS_HISTORY
VALUES ('002','2/15/2008',null,'005','001')
INSERT INTO JOBS_HISTORY
VALUES ('003','7/5/2012',null,'003','004')
INSERT INTO JOBS_HISTORY
VALUES ('004','5/22/2010',null,'004','003')
INSERT INTO JOBS_HISTORY
VALUES ('005','06/30/2015',null,'004','005')

/* Show the list of employees having manager_id */
SELECT *
FROM EMPLOYEES
WHERE MANAGER_ID IS NOT NULL

/* Show the list of employees having manager_id and sort by manager_id */
SELECT *
FROM EMPLOYEES
WHERE MANAGER_ID IS NOT NULL
ORDER BY MANAGER_ID

/* Show the emp_id employees named Mary */
SELECT EMP_ID
FROM EMPLOYEES
WHERE EMPNAME = 'Mary'

/* Show the departments managed by harry */
SELECT DP.DEPT_ID, DP.DEPTNAME
FROM DEPARTMENTS DP, EMPLOYEES EM
WHERE DP.DEPT_MNG = EM.EMP_ID AND EM.EMPNAME = 'Harry'

/* Show the departments managed by harry or located at new york */
SELECT DISTINCT DP.DEPT_ID, DP.DEPTNAME
FROM DEPARTMENTS DP, EMPLOYEES EM, LOCATIONS LC
WHERE (DP.DEPT_MNG = EM.EMP_ID AND EM.EMPNAME = 'Harry')
OR (DP.LOCATION_ID = LC.LOC_ID AND LC.CITY = 'New York')

/* Show the emp_id of employees named mary and salary > 1000 */
SELECT *
FROM EMPLOYEES
WHERE EMPNAME = 'Mary' AND SALARY > 1000

/* Add 1000 to salary of employees having empname = 'Mary' */
SELECT EMP_ID, EMPNAME, SALARY + 1000
FROM EMPLOYEES
WHERE EMPNAME = 'Mary' 

/* create the index */
CREATE INDEX index_manager ON EMPLOYEES(MANAGER_ID) 

CREATE INDEX index_empname ON EMPLOYEES(EMPNAME) 

CREATE INDEX index_EmpnameAndSalary ON EMPLOYEES(EMPNAME,SALARY)

