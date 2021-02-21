CREATE DATABASE COMPANY_DB;

USE COMPANY_DB;

CREATE TABLE EMPLOYEE
(
	Eno	          CHAR(3)       NOT NULL,
	Ename         VARCHAR(50)   NOT NULL,
	Job_type      VARCHAR(50)   NOT NULL,
	SupervisorEno CHAR(3)       DEFAULT NULL,
	Hire_date     DATE          NOT NULL,
	Dno           INT           DEFAULT NULL,
	Commission    DECIMAL(10,2) DEFAULT NULL,
	Salary        DECIMAL(7,2)  NOT NULL,
	PRIMARY KEY (Eno)
);

CREATE TABLE DEPARTMENT
(
	Dno      INT         NOT NULL,
	Dname    VARCHAR(50) DEFAULT NULL,
	Location VARCHAR(50) DEFAULT 'New Delhi',
	PRIMARY KEY (Dno)
);

ALTER TABLE EMPLOYEE
	ADD CONSTRAINT Supervisor_Constraint
		FOREIGN KEY (SupervisorEno) REFERENCES EMPLOYEE(Eno);

ALTER TABLE EMPLOYEE
	ADD CONSTRAINT DepartmentNo_Constraint
		FOREIGN KEY (Dno) REFERENCES DEPARTMENT(Dno);

INSERT INTO DEPARTMENT
	VALUES (10, 'HEADQUARTERS', 'Noida'),
		   (20, 'SECURITY', 'Bengaluru'),
		   (50, 'PURCHASE', 'Noida'),
		   (60, 'MARKETING', 'Mumbai'),
		   (70, 'SALES', 'Dallas'),
		   (80, 'IT', 'Dallas');

INSERT INTO DEPARTMENT (Dno, Dname)
	VALUES (30, 'EXECUTIVE'),
		   (40, 'ACCOUNTANCY');

INSERT INTO EMPLOYEE
	VALUES ('101', 'SHUBHANG GUPTA', 'Senior Security Engineer', '778', 'May 18, 1980', 20, 2000.00, 8000.00),
		   ('102', 'ANMOL GUPTA', 'Junior Security Engineer', '101', 'August 11, 1981', 20, 1000.00, 5000.00),
		   ('103', 'KUSHAN THAKUR', 'Chief Operating Officer', '778', 'April 21, 1978', 30, 2000.00, 5000.00),
		   ('104', 'KUNAL GIRI', 'Operating Officer', '103', 'September 30, 1985', 30, 1000.00, 4000.00),
		   ('778', 'ANKUR KUMAR', 'Managing Director', NULL, 'November 01, 1972', 10, 2000.00, 6000.00),
		   ('106', 'LIPSA PRAHARAJ', 'Accountant', '778', 'December 01, 1979', 40, 2000.00, 7000.00),
           ('107', 'DEVASHISH TYAGI', 'Accountant Intern', '106', 'June 28, 1981', 40, NULL, 800.00),
		   ('108', 'RAHUL SAHAY', 'Security Intern', '102', 'July 19, 1990', 20, NULL, 900.00),
		   ('109', 'TANIA CHAUHAN', 'Executive Intern', '104', 'May 22, 1989', 30, NULL, 800.00),
		   ('79', 'SANYEM NAZKANI', 'Human Resource (HR)', NULL, 'April 01, 1987', 10, 1000.00, 5000.00),
           ('110', 'ALICIA JONES', 'Purchase Manager', '778', 'October 26, 1982', 50, 1452.40, 7500.35),
           ('111', 'ANAMIKA GHAI', 'Accountant Intern', '106', 'June 28, 1981', 40, NULL, 800.00),
		   ('112', 'AMARTYA SHARMA', 'Security Intern', '102', 'July 19, 1990', 20, NULL, 900.00),
		   ('113', 'SAMEER', 'Executive Intern', '104', 'May 22, 1989', 30, NULL, 800.00),
		   ('114', 'DUSHYANT KUMAR', 'Sales Director', NULL, 'April 01, 1987', 70, 1000.00, 7500.35),
           ('115', 'LAKSHYA SHARMA', 'SDE Manager', '778', 'October 26, 1982', 80, 1500.00, 8000.35),
		   ('116', 'RODRICK HAIGHTON', 'Graphic Designer', '115', 'May 08, 2000', 80, 1000.00, 2027.74),
           ('117', 'NINA FISBY', 'Systems Administrator', '115', 'July 26, 2017', 80, 524.39, 1920.84),
           ('118', 'SKELL WOOLERTON', 'Software Test Engineer', '115', 'April 04, 2004', 80, 900.86, 2027.74),
           ('119', 'CORNIE MUNBY', 'Software Consultant', '115', 'June 07, 1986', 80, NULL, 688.37),
           ('120', 'LAYTON MURRIE', 'Graphic Designer', '115', 'June 24, 2006', 80, 1200, 2640.31),
           ('121', 'RIVY BUZEK', 'Help Desk Technician', NULL, 'May 25, 1982', 80, NULL, 1095.31);

INSERT INTO EMPLOYEE
	VALUES ('122', 'BLAKE LEWIS', 'Backend Developer', '115', 'May 25, 1989', 80, 1200.00, 5500.00),
		   ('123', 'BRANDTR WILDBORE', 'Software Test Engineer', '115', 'April 14, 2000', 80, NULL, 2704.23),
           ('124', 'KING SIXSMITH', 'Sales Manager', '114', 'July 07, 2005', 70, 530.53, 4387.43),
           ('125', 'ONEIDA HICKLINGBOTTOM', 'Payment Coordinator', '110', 'March 25, 2006', 50, NULL, 1789.82),
           ('126', 'GANNIE QUANTRELL', 'Automation Engineer', '115', 'April 29, 2019', 80, NULL, 3174.12),
           ('127', 'FRAN LENING', 'Analyst Programmer', '115', 'May 27, 1981', 80, NULL, 2471.17),
           ('128', 'ULBERTO GOSZ', 'Office Assistant', '778', 'February 07, 2017', 10, NULL, 4381.64),
           ('129', 'SHAY RESTIEAUX', 'Junior Security Engineer', '101', 'April 16, 1999', 20, 574.68, 5500.22),
           ('130', 'MARCILLE OCCLESHAW', 'Sales Representative', '124', 'December 27, 2003', 70, 453.52, 4507.10),
           ('131', 'DESIRI ALLOTT', 'Payment Coordinator', '110', 'November 04, 1997', 50, 239.84, 2683.09),
           ('132', 'LAURENCE GROSVENER', 'Sales Intern', '124', 'September 06, 2019', 70, 125.45, 444.37),
           ('133', 'GUSTAV WARING', 'Software Engineer', '115', 'December 23, 2002', 80, NULL, 3141.05),
           ('134', 'VIRGE SWANCOTT', 'Web Developer', '115', 'January 23, 1984', 80, NULL, 3292.48),
           ('135', 'LEE PRATTIN', 'Frontend Developer', '115', 'January 23, 1986', 80, NULL, 2296.48),
           ('136', 'MAG GIACOMO', 'Frontend Developer', '115', 'December 23, 2002', 80, NULL, 2427.98),
           ('137', 'CHANDAL BRIER', 'Software Consultant', '115', 'February 10, 1998', 80, NULL, 1697.68),
           ('138', 'MARTHA ANNIES', 'Web Developer', '115', 'February 03, 2008', 80, NULL, 3200.80),
           ('139', 'SELESTINA HERRIES', 'Software Engineer', '115', 'May 23, 2013', 80, NULL, 2239.27),
           ('140', 'ASHIL BURNEY', 'Operating Clerk', '104', 'March 29, 1987', 30, NULL, 1586.13),
		   ('141', 'NETTI DELLENBROK', 'Marketing Head', '778', 'May 14, 2014', 60, 600.25, 4790.82),
           ('142', 'SALMON GOUGH', 'Marketing Assistant', '141', 'December 13, 2008', 60, 148.80, 2998.32),
           ('143', 'BERNY BONAS', 'Executive Secretary', '104', 'December 24, 2008', 30, NULL, 1779.34),
		   ('144', 'MARIE BRAHMS', 'Executive Secretary', '104', 'June 22, 1983', 30, NULL, 1876.78),
           ('145', 'MAHALA BURTWHISTLE', 'Accountant', '778', 'August 20, 1990', 40, NULL, 2602.86),
           ('146', 'BRYNA KENNY', 'Help Desk Technician', NULL, 'October 11, 2001', 80, NULL, 1693.63),
           ('147', 'JIM HALPERT', 'Backend Developer', '115', 'November 07, 2017', 80, NULL, 3381.64),
           ('148', 'JOSH PORTER', 'Automation Engineer', '115', 'May 15, 2014', 80, NULL, 2790.82),
           ('149', 'DAVID WALLACE', 'Sales Representative', '124', 'December 14, 2008', 70, NULL, 1998.32),
           ('150', 'JAN LEVINSON', 'Sales Intern', '124', 'May 24, 2008', 70, NULL, 779.34),
           ('151', 'LOWELL PAULE', 'Systems Administrator', '115', 'October 30, 2008', 80, 324.39, 1969.66),
           ('152', 'NICHOLAS COMELINI', 'Analyst Programmer', '115', 'June 20, 1997', 80, 546.04, 2882.53),
           ('153', 'DUNMORE HIGHSCHOOL', 'Financial Advisor', '141', 'December 18, 2004', 60, 148.80, 2998.32),
           ('154', 'SCRANTON WHITEPAGES', 'Marketing Assistant', '141', 'August 18, 2008', 60, NULL, 1779.34),
           ('155', 'ANDY BERNARD', 'Financial Advisor', '141', 'September 29, 2008', 60, 324.39, 2969.66),
		   ('156', 'MICHAEL SCOTT', 'Compensation Analyst', '110', 'September 25, 1999', 50, NULL, 1602.86),
		   ('157', 'DANEL MONDADORI', 'Accountant Intern', '106', 'September 28, 2016', 40, NULL, 800.00),
		   ('158', 'PARVIZ LORTZ', 'Security Intern', '102', 'October 19, 2015', 20, NULL, 900.00),
		   ('159', 'SOMNATH FOOTE', 'Executive Intern', '104', 'May 18, 2016', 30, NULL, 800.00),
		   ('160', 'CHIKARA RISSLAND', 'Accountant Intern', '106', 'June 01, 2015', 40, NULL, 800.00),
		   ('161', 'YOZA HILTGEN', 'Security Intern', '102', 'July 06, 2015', 20, NULL, 900.00),
		   ('162', 'ARMOND PEIR', 'Executive Intern', '104', 'May 12, 2016', 30, NULL, 800.00);

SELECT * FROM EMPLOYEE;

SELECT * FROM DEPARTMENT;



-- UPDATE EMPLOYEE
-- SET SupervisorEno = NULL WHERE Eno = '114';

-- ALTER TABLE EMPLOYEE
--	DROP CONSTRAINT DepartmentNo_Constraint;

-- ALTER TABLE EMPLOYEE
--	DROP CONSTRAINT Supervisor_Constraint;

-- UPDATE DEPARTMENT
-- SET Dname = 'PURCHASE' WHERE Dno = 50;

-- DELETE FROM EMPLOYEE;
-- DELETE FROM DEPARTMENT;
-- DROP DATABASE COMPANY_DB;
-- DROP TABLE EMPLOYEE;
-- DROP TABLE DEPARTMENT;