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
		   (50, 'Purchase', 'Noida');

INSERT INTO DEPARTMENT (Dno, Dname)
	VALUES (30, 'EXECUTIVE'),
		   (40, 'ACCOUNTANCY');

INSERT INTO DEPARTMENT
	VALUES (50, 'IT', 'Dallas'),
		   (60, 'MARKETING', 'Mumbai'),
		   (70, 'SALES', 'Dallas');

INSERT INTO EMPLOYEE
	VALUES ('101', 'SHUBHANG GUPTA', 'Senior Security Engineer', '778', 'May 18, 1980', 20, 2000.00, 8000.00),
		   ('102', 'ANMOL GUPTA', 'Junior Security Engineer', '101', 'August 11, 1981', 20, 1000.00, 5000.00),
		   ('103', 'KUSHAN THAKUR', 'Chief Operating Officer', '778', 'April 21, 1978', 30, 2000.00, 5000.00),
		   ('104', 'KUNAL GIRI', 'Operating Officer', '103', 'September 30, 1985', 30, 1000.00, 4000.00),
		   ('778', 'ANKUR KUMAR', 'Managing Director', NULL, 'November 01, 1972', 10, 2000.00, 6000.00),
		   ('106', 'LIPSA PRAHARAJ', 'Accountant', '778', 'December 01, 1979', 40, 2000.00, 7000.00);

INSERT INTO EMPLOYEE
	VALUES ('107', 'DEVASHISH TYAGI', 'Accountant Intern', '106', 'June 28, 1981', 40, NULL, 2500.00),
		   ('108', 'RAHUL SAHAY', 'Security Intern', '102', 'July 19, 1990', 20, NULL, 2800.00),
		   ('109', 'TANIA CHAUHAN', 'Executive Intern', '104', 'May 22, 1989', 30, NULL, 2000.00),
		   ('79', 'SANYEM NAZKANI', 'Human Resource (HR)', NULL, 'April 01, 1987', 10, 1000.00, 5000.00),
           ('110', 'ALICIA JONES', 'Purchase Manager', '778', 'October 26, 1982', 50, NULL, 9800.35);

INSERT INTO EMPLOYEE
	VALUES ('111', 'ANAMIKA GHAI', 'Accountant Intern', '106', 'June 28, 1981', 40, NULL, 2500.00),
		   ('112', 'AMARTYA SHARMA', 'Security Intern', '102', 'July 19, 1990', 20, NULL, 2800.00),
		   ('113', 'SAMEER', 'Executive Intern', '104', 'May 22, 1989', 30, NULL, 2000.00),
		   ('114', 'DUSHYANT KUMAR', 'Human Resource (HR)', NULL, 'April 01, 1987', 10, 1000.00, 5000.00),
           ('115', 'LAKSHYA SHARMA', 'Purchase Manager', '778', 'October 26, 1982', 50, NULL, 9800.35);

SELECT * FROM EMPLOYEE;

SELECT * FROM DEPARTMENT;



-- UPDATE DEPARTMENT
-- SET Dname = 'PURCHASE' WHERE Dno = 50;

-- ALTER TABLE EMPLOYEE
--	DROP CONSTRAINT DepartmentNo_Constraint;

-- ALTER TABLE EMPLOYEE
--	DROP CONSTRAINT Supervisor_Constraint;

-- DELETE FROM EMPLOYEE;
-- DELETE FROM DEPARTMENT;
-- DROP DATABASE COMPANY_DB;
-- DROP TABLE EMPLOYEE;
-- DROP TABLE DEPARTMENT;