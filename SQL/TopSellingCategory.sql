--Find the product category with the highest total sales revenue.
SELECT c.CategoryName, SUM(o.Amount) AS TotalRevenue
FROM Orders o
JOIN Products p ON o.ProductId = p.Id
JOIN Categories c ON p.CategoryId = c.Id
GROUP BY c.CategoryName
ORDER BY TotalRevenue DESC
LIMIT 1;
