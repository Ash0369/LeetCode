SELECT Max(salary) as SecondHighestSalary
FROM Employee 
WHERE salary <> (SELECT Max(salary) FROM Employee)
