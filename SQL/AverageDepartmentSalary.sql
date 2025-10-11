--Problem: Find employees earning above the average salary of their department.
SELECT e.Name, e.Salary, d.Name AS Department
FROM Employee e
JOIN Department d ON e.DepartmentId = d.Id
WHERE e.Salary > (
    SELECT AVG(Salary)
    FROM Employee
    WHERE DepartmentId = e.DepartmentId
);
