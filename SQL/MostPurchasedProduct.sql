SELECT ProductId, COUNT(*) AS TotalPurchases
FROM Orders
GROUP BY ProductId
HAVING COUNT(*) = (
    SELECT MAX(cnt)
    FROM (
        SELECT COUNT(*) AS cnt
        FROM Orders
        GROUP BY ProductId
    ) AS sub
);
