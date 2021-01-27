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

INSERT INTO EMPLOYEE
	VALUES ('101', 'SHUBHANG GUPTA', 'Senior Security Engineer', '105', 'May 18, 2022', 1, 20000.00, 80000.00),
		   ('102', 'ANMOL GUPTA', 'Junior Security Engineer', '101', 'August 11, 2024', 1, 10000.00, 50000.00),
		   ('103', 'KUSHAN THAKUR', 'Chief Operating Officer', '105', 'April 21, 2022', 2, 20000.00, 50000.00),
		   ('104', 'KUNAL GIRI', 'Operating Officer', '103', 'September 30, 2025', 2, 10000.00, 40000.00),
		   ('105', 'ANKUR KUMAR', 'Managing Director', NULL, 'November 01, 2022', 0, 20000.00, 60000.00),
		   ('106', 'LIPSA PRAHARAJ', 'Accountant', '105', 'December 01, 2023', 3, 20000.00, 70000.00);

INSERT INTO EMPLOYEE
	VALUES ('107', 'DEVASHISH TYAGI', 'Accountant Intern', '106', 'June 28, 2025', 3, 0.00, 2500.00),
		   ('108', 'RAHUL SAHAY', 'Security Intern', '102', 'July 19, 2025', 1, 0.00, 2800.00),
		   ('109', 'TANIA CHAUHAN', 'Executive Intern', '104', 'May 22, 2025', 2, 0.00, 2000.00);

INSERT INTO EMPLOYEE
	VALUES ('79', 'SANYEM NAZKANI', 'Human Resource (HR)', NULL, 'April 01, 2022', 0, 10000.00, 50000.00);

INSERT INTO DEPARTMENT
	VALUES (0, 'HEADQUARTERS', 'Noida'),
		   (1, 'SECURITY', 'Noida');

INSERT INTO DEPARTMENT (Dno, Dname)
	VALUES (2, 'EXECUTIVE'),
		   (3, 'ACCOUNTANCY');

SELECT * FROM EMPLOYEE;

SELECT * FROM DEPARTMENT;








-- DROP DATABASE COMPANY_DB;
-- DROP TABLE EMPLOYEE;
-- DROP TABLE DEPARTMENT;