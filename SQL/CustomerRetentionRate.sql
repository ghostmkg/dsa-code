--Find the percentage of customers who placed more than one order.
SELECT 
  ROUND(
    (COUNT(DISTINCT CASE WHEN order_count > 1 THEN CustomerId END) * 100.0 /
     COUNT(DISTINCT CustomerId)), 2
  ) AS RetentionRate
FROM (
    SELECT CustomerId, COUNT(*) AS order_count
    FROM Orders
    GROUP BY CustomerId
) AS customer_orders;
