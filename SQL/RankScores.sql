--Problem: Rank scores without skipping ranks (dense ranking).
SELECT Score,
       DENSE_RANK() OVER (ORDER BY Score DESC) AS Rank
FROM Scores;
