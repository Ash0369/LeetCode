# Write your MySQL query statement below
SELECT Department.name as Department ,Employee.name as Employee,Employee.salary as Salary
FROM Employee JOIN Department WHERE Employee.departmentId=Department.id AND (Employee.departmentId,Employee.salary) IN (SELECT departmentId,MAX(salary) FROM Employee GROUP BY departmentID)
