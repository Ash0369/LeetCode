SELECT Salaries.employee_id 
FROM Salaries
WHERE Salaries.employee_id NOT IN(SELECT Salaries.employee_id FROM Employees join Salaries ON Salaries.employee_id=Employees.employee_id)
UNION
SELECT Employees.employee_id 
FROM Employees
WHERE Employees.employee_id NOT IN(SELECT Employees.employee_id FROM Employees join Salaries ON Salaries.employee_id=Employees.employee_id)
ORDER BY employee_id
