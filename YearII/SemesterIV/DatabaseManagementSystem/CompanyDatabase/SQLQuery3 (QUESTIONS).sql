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

SELECT Ename,
       Dno
FROM EMPLOYEE
WHERE Dno = 10 OR Dno = 30
ORDER BY Ename;

-- 9. Query to display Name and Hire Date of every Employee who was hired in 1981.

SELECT Ename,
       Hire_date
FROM EMPLOYEE
WHERE Hire_date LIKE '1981______';

-- 10. Query to display Name and Job of all employees who have not assigned a supervisor.

SELECT Ename,
       Job_type
FROM EMPLOYEE
WHERE SupervisorEno IS NULL;

-- 11. Query to display the Name, Salary and Commission for all the employees who earn commission.

SELECT Ename,
       Job_type
FROM EMPLOYEE
WHERE Commission != 0.00;

-- 12. Sort the data in descending order of Salary and Commission.

SELECT *
FROM EMPLOYEE
ORDER BY Salary DESC, Commission DESC;

-- 13. Query to display Name of all the employees where the third letter of their name is ‘A’.

SELECT Ename
FROM EMPLOYEE
WHERE Ename LIKE '__A%';

-- 14. Query to display Name of all employees either have two ‘R’s or have two ‘A’s in their name and
--     are either in Dept No = 30 or their Manger’s Employee No = 7788.

SELECT Ename
FROM EMPLOYEE
WHERE (Ename LIKE '%L%L%' or
       Ename LIKE '%A%A%') AND
	  (Dno = 30 or SupervisorEno = 7788);

-- 15. Query to display Name, Salary and Commission for all employees whose
--     Commission amount is greater than their Salary increased by 5%.

-- In real life scenarios Commission can not be greater than Salary.

-- 16. Query to display the Current Date along with the day name.

SELECT CONCAT(CAST(GETDATE() AS DATE), ', ',
              DATENAME(dw, GETDATE())) AS Date_Day;
-- CAST Syntax:  
-- CAST ( expression AS data_type [ ( length ) ] )

-- 17. Query to display Name, Hire Date and Salary Review Date which is the 1st Monday after six months of employment.

SELECT Ename,
       Hire_date,
	   DATEADD(day, 9 - 
	                 CASE
	                     WHEN DATEPART(weekday, DATEADD(month, 6, Hire_date)) = 1	-- For Sunday
	                         THEN 8
	                     WHEN DATEPART(weekday, DATEADD(month, 6, Hire_date)) = 2	-- For Monday
			    	         THEN 9
			    	     ELSE DATEPART(weekday, DATEADD(month, 6, Hire_date))		-- For rest of the days
		             END,
		       DATEADD(month, 6, Hire_date))
	   AS Salary_review_date
FROM EMPLOYEE;

-- 18. Query to display Name and calculate the number of months between today and the date
--     on which employee was hired of department ‘Purchase’.

SELECT Ename,
       DATEDIFF(month, Hire_date, GETDATE()) -
       CASE
	       WHEN DATEPART(day, Hire_date) > DATEPART(day, GETDATE())
		       THEN 1
		       ELSE 0
		END
		AS Months
FROM EMPLOYEE, DEPARTMENT
WHERE EMPLOYEE.Dno = DEPARTMENT.Dno AND
      Dname = 'PURCHASE';

-- 19. Query to display the following for each employee <E-Name> earns <Salary> monthly but
--     wants < 3 * Current Salary >. Label the Column as Dream Salary.

SELECT CONCAT(Ename, ' earns ',
              Salary, ' monthly but wants ',
			  3*Salary, '.')
AS Dream_Salary
FROM EMPLOYEE;

-- 20. Query to display Name with the 1st letter capitalized and all other letter lower case and
--     length of their name of all the employees whose name starts with ‘J’, ’A’ and ‘M’.

SELECT UPPER(LEFT(Ename, 1)) +
       LOWER(SUBSTRING(Ename, 2, LEN(Ename)))
	       AS Names,
	   LEN(Ename)
	       AS Length
FROM EMPLOYEE
WHERE Ename LIKE 'J%' OR
      Ename LIKE 'A%' OR
	  Ename LIKE 'M%';

-- 21. Query to display Name, Hire Date and Day of the week on which the employee started.

SELECT Ename,
       Hire_date,
	   DATENAME(WEEKDAY, Hire_date)
	       AS 'DayOfWeek'
FROM EMPLOYEE;

-- 22. Query to display Name, Department Name and Department No for all the employees.

SELECT Ename,
       Dname,
	   DEPARTMENT.Dno
FROM EMPLOYEE, DEPARTMENT
WHERE EMPLOYEE.Dno = DEPARTMENT.Dno;

-- 23. Query to display Unique Listing of all Jobs that are in Department number 30.

SELECT DISTINCT Job_type
FROM EMPLOYEE
WHERE Dno = 30;

-- 24. Query to display Name, Dept Name of all employees who have an ‘A’ in their name.

SELECT Ename, 
       Dname
FROM EMPLOYEE AS E, DEPARTMENT AS D
WHERE Ename LIKE '%A%' AND
      E.Dno = D.Dno;

-- 25. Query to display Name, Job, Department No. And Department Name for all the employees
--	   working at the Dallas location.

SELECT Ename,
       Job_type,
	   D.Dno,
	   Dname
FROM EMPLOYEE AS E, DEPARTMENT AS D
WHERE Location LIKE 'Dallas' AND
      E.Dno = D.Dno;

-- 26. Query to display Name and Employee no. Along with their supervisor’s Name and the supervisor’s
--	   employee no; along with the Employees’ Name who do not have a supervisor.

SELECT Eno,
       Ename,
	   SupervisorEno,
	   (SELECT Ename
	        FROM EMPLOYEE AS E2
			    WHERE E1.SupervisorEno = E2.Eno)
				    AS Supervisor_Name
FROM EMPLOYEE AS E1;

-- 27. Query to display Name, Dept No. And Salary of any employee whose department No. and salary matches
--	   both the department no. And the salary of any employee who earns a commission.

SELECT E1.Ename,
       E1.Dno,
       E1.Salary
FROM EMPLOYEE E1, EMPLOYEE E2
WHERE E1.Dno = E2.Dno AND
      E1.Salary = E2.Salary AND
	  E1.Ename <> E2.Ename AND
	  E2.Commission IS NOT NULL;

-- 28. Query to display Name and Salaries represented by asterisks, where each asterisk (*) signifies $100.

SELECT Ename,
       REPLICATE('*', Salary / 100)
	       AS Salary_Star
FROM EMPLOYEE;

-- 29. Query to display the Highest, Lowest, Sum and Average Salaries of all the employees.

SELECT MAX(Salary) AS Highest,
       MIN(Salary) AS Lowest,
	   SUM(Salary) AS Sum,
	   AVG(Salary) AS Average
FROM EMPLOYEE;

-- 30. Query to display the number of employees performing the same Job type functions.

SELECT Job_type,
       COUNT(Job_type) AS COUNT
FROM EMPLOYEE
GROUP BY Job_type;

-- 31. Query to display the total number of supervisors without listing their names.

SELECT COUNT(DISTINCT SupervisorEno)
           AS Total_Supervisors
FROM EMPLOYEE;

-- 32. Query to display the Department Name, Location Name, No. of Employees and the average salary for
-- all employees in that department.

SELECT Dname,
       Location,
	   COUNT(Eno) AS No_of_Employees,
	   AVG(Salary) AS Average_Salary
FROM EMPLOYEE E, DEPARTMENT D
WHERE E.Dno = D.Dno
GROUP BY Dname, Location;

-- 33. Query to display Name and Hire Date for all employees in the same dept. as Blake.

SELECT E1.Ename,
       E1.Hire_date
FROM EMPLOYEE E1
WHERE E1.Dno = (SELECT E2.Dno
                    FROM EMPLOYEE E2
					    WHERE E2.Ename LIKE 'BLAKE%');

-- 34. Query to display the Employee No. And Name for all employees who earn more than the average salary.

SELECT Eno,
       Ename
FROM EMPLOYEE
WHERE Salary > (SELECT AVG(Salary)
                    FROM EMPLOYEE);

-- 35. Query to display Employee Number and Name for all employees who work in a department with any employee
--	   whose name contains a ‘T’.

SELECT Eno,
       Ename
FROM EMPLOYEE
WHERE Dno IS NOT NULL AND
      Ename LIKE '%T%';

-- 36. Query to display the names and salaries of all employees who report to supervisor named ‘King’.

SELECT E1.Ename,
       E1.Salary
FROM EMPLOYEE E1
WHERE E1.SupervisorEno = (SELECT E2.Eno
                              FROM EMPLOYEE E2
							      WHERE E2.Ename LIKE 'KING%');

-- 37. Query to display the department no, name and job for all employees in the Sales department.

SELECT E.Dno,
       Ename,
	   Job_Type
FROM EMPLOYEE E, DEPARTMENT D
WHERE E.Dno = D.Dno AND
      Dname LIKE 'SALES';

-- 38. Display names of employees along with their department name who have more than 20 years experience.

SELECT Ename,
       Dname
FROM EMPLOYEE E, DEPARTMENT D
WHERE E.Dno = D.Dno AND
      DATEDIFF(YEAR, Hire_date, CAST(GETDATE() AS DATE)) > 20;

-- 39. Display total number of departments at each location.

SELECT Location,
       COUNT(*) AS TOTAL_DEPTS
FROM DEPARTMENT
GROUP BY Location;

-- 40. Find the department name in which at least 20 employees work in.

SELECT Dname
FROM EMPLOYEE E INNER JOIN DEPARTMENT D
                  ON E.Dno = D.Dno
GROUP BY D.Dname
HAVING COUNT(*) >= 20;

-- 41. Query to find the employee’s name who is not supervisor and name of supervisor supervising more
--	   than 5 employees.

(
    SELECT Ename
	FROM EMPLOYEE
	WHERE Eno NOT IN(
	    SELECT DISTINCT SupervisorEno
		FROM EMPLOYEE
		WHERE SupervisorEno IS NOT NULL
	)
)
UNION
(
    SELECT Ename
	FROM EMPLOYEE
	WHERE Eno IN(
	    SELECT SupervisorEno
		FROM EMPLOYEE
		WHERE SupervisorEno IS NOT NULL
		GROUP BY SupervisorEno
		HAVING COUNT(*) > 5
	)
);

-- 42. Query to display the job type with maximum and minimum employees.

SELECT Job_type,
       COUNT(*) AS Count
FROM EMPLOYEE
GROUP BY Job_type
HAVING COUNT(*) IN (
    (
        SELECT MAX(ECount)
        FROM (
                 SELECT COUNT(*) AS ECount
                 FROM EMPLOYEE
                 GROUP BY Job_type
             ) AS E1
    )
    UNION
    (
        SELECT MIN(ECount)
        FROM (
                 SELECT COUNT(*) AS ECount
                 FROM EMPLOYEE
                 GROUP BY Job_type
             ) AS E2
    )
);