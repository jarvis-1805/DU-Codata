USE COMPANY_DB;

-- 1. Query to display Employee Name, Job, Hire Date, Employee Number;
--    for each employee with the Employee Number appearing first.

SELECT Eno,
       Ename,
       Job_type,
       Hire_date
FROM EMPLOYEE;

-- 2. Query to display unique Jobs from the Employee Table.

SELECT DISTINCT Job_type
FROM EMPLOYEE;

-- 3. Query to display the Employee Name concatenated by a Job separated by a comma.

SELECT CONCAT (Ename, ' , ', Job_type)
AS 'Employee_Name + Job_Type'
FROM EMPLOYEE;

-- 4. Query to display all the data from the Employee Table. Separate each column by
--    a comma and name the said column as THE_OUTPUT.

SELECT CONCAT (
				Eno, ' , ',
				Ename, ' , ',
				Job_type, ' , ',
				SupervisorEno, ' , ',
				Hire_date, ' , ',
				Dno, ' , ',
				Commission, ' , ',
				Salary
			  ) AS THE_OUTPUT
FROM EMPLOYEE;

-- 5. Query to display the Employee Name and Salary of all the employees earning more than $2850.

SELECT Ename,
	   Salary
FROM EMPLOYEE
WHERE Salary > 2850.00;

-- 6. Query to display Employee Name and Department Number for the Employee No = 79.

