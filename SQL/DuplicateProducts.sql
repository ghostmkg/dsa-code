--Problem: Find product names that appear more than once.
SELECT ProductName, COUNT(*) AS Count
FROM Products
GROUP BY ProductName
HAVING COUNT(*) > 1;
