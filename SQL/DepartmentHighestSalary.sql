--Problem: Find the employee(s) who have the highest salary in each department.
SELECT d.Name AS Department,
       e.Name AS Employee,
       e.Salary
FROM Employee e
JOIN Department d ON e.DepartmentId = d.Id
WHERE (e.Salary, e.DepartmentId) IN (
    SELECT MAX(Salary), DepartmentId
    FROM Employee
    GROUP BY DepartmentId
);
