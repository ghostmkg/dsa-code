--Find the city with the highest average employee salary.
SELECT City, AVG(Salary) AS AvgSalary
FROM Employee
GROUP BY City
ORDER BY AvgSalary DESC
LIMIT 1;
