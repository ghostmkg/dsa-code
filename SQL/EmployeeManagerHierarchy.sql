SELECT e.Name AS Employee,
       m.Name AS Manager
FROM Employee e
LEFT JOIN Employee m ON e.ManagerId = m.Id;
