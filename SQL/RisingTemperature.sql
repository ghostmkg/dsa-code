--Problem: Find all dates when the temperature was higher than the previous day.
SELECT w1.Id
FROM Weather w1
JOIN Weather w2
  ON DATEDIFF(w1.RecordDate, w2.RecordDate) = 1
WHERE w1.Temperature > w2.Temperature;
