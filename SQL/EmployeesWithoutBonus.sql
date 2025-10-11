--List employees who have never received a bonus.
SELECT e.Name
FROM Employee e
LEFT JOIN Bonus b ON e.Id = b.EmployeeId
WHERE b.BonusAmount IS NULL;
