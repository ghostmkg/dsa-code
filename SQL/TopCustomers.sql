--Problem: Find the top 3 customers by total order amount.
SELECT c.Name, SUM(o.Amount) AS TotalSpent
FROM Customers c
JOIN Orders o ON c.Id = o.CustomerId
GROUP BY c.Id, c.Name
ORDER BY TotalSpent DESC
LIMIT 3;
