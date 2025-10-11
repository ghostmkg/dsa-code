SELECT DISTINCT Num AS ConsecutiveNums
FROM (
  SELECT Num,
         LEAD(Num, 1) OVER (ORDER BY Id) AS next1,
         LEAD(Num, 2) OVER (ORDER BY Id) AS next2
  FROM Logs
) t
WHERE Num = next1 AND Num = next2;
