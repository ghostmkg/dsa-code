--Calculate month-over-month revenue growth percentage.
WITH monthly_sales AS (
    SELECT DATE_FORMAT(OrderDate, '%Y-%m') AS Month,
           SUM(Amount) AS Revenue
    FROM Orders
    GROUP BY DATE_FORMAT(OrderDate, '%Y-%m')
)
SELECT Month,
       Revenue,
       ROUND(((Revenue - LAG(Revenue) OVER (ORDER BY Month)) / 
              LAG(Revenue) OVER (ORDER BY Month)) * 100, 2) AS GrowthPercent
FROM monthly_sales;
