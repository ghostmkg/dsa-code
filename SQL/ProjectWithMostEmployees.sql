SELECT ProjectId, COUNT(EmployeeId) AS TotalEmployees
FROM Project
GROUP BY ProjectId
ORDER BY TotalEmployees DESC
LIMIT 1;
