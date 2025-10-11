SELECT DATE_FORMAT(ActivityDate, '%Y-%m') AS Month,
       COUNT(DISTINCT UserId) AS ActiveUsers
FROM UserActivity
GROUP BY DATE_FORMAT(ActivityDate, '%Y-%m')
ORDER BY Month;
