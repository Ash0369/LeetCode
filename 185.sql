SELECT Department.name as Department,Employee.name as Employee,Employee.salary as Salary
FROM Employee, Department WHERE Employee.departmentId=Department.id AND (Employee.departmentId,Employee.salary) IN 
(SELECT edi,es FROM (SELECT Employee.departmentID as edi,Employee.salary as es,dense_rank() over (partition by Employee.departmentId order by Employee.salary DESC) as rn from Employee) new_table WHERE rn<=3)
