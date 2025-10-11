--Problem: Find employees working on more than 2 projects.
SELECT e.EmployeeId
FROM EmployeeProject e
GROUP BY e.EmployeeId
HAVING COUNT(e.ProjectId) > 2;
