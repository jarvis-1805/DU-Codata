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

SELECT Ename,
       Dno
FROM EMPLOYEE
WHERE Eno = 79;

-- 7. Query to display Employee Name and Salary for all employees whose salary
--    is not in the range of $1500 and $2850.

SELECT Ename,
       Salary
FROM EMPLOYEE
WHERE Salary < 1500 OR Salary > 2850;

-- 8. Query to display Employee Name and Department No. of all the employees in Dept 10 and
--    Dept 30 in the alphabetical order by name.

-- 9. Query to display Name and Hire Date of every Employee who was hired in 1981.
-- 10. Query to display Name and Job of all employees who have not assigned a supervisor.
-- 11. Query to display the Name, Salary and Commission for all the employees who earn commission.
-- 12. Sort the data in descending order of Salary and Commission. 13. Query to display Name of all
--     the employees where the third letter of their name is ‘A’.
-- 14. Query to display Name of all employees either have two ‘R’s or have two ‘A’s in their name and
--     are either in Dept No = 30 or their Manger’s Employee No = 7788. 15. Query to display Name, Salary and
-- 	Commission for all employees whose Commission amount is greater than their Salary increased by 5%.
-- 16. Query to display the Current Date along with the day name. 
-- 17. Query to display Name, Hire Date andSalary Review Date which is the 1st Monday after six months of employment.
-- 18. Query to display Name and calculate the number of months between today and the date
--     on which employee was hired of department ‘Purchase’.
-- 19. Query to display the following for each employee <E-Name> earns < Salary> monthly but
--     wants < 3 * Current Salary >. Label the Column as Dream Salary.
-- 20. Query to display Name with the 1st letter capitalized and all other letter lower case and
--     length of their name of all the employees whose name starts with ‘J’, ’A’ and ‘M’.