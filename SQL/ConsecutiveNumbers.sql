<<<<<<< main
--Problem: Find numbers appearing consecutively at least 3 times.
SELECT DISTINCT num AS ConsecutiveNums
FROM Logs l1
JOIN Logs l2 ON l1.Id = l2.Id - 1 AND l1.Num = l2.Num
JOIN Logs l3 ON l2.Id = l3.Id - 1 AND l2.Num = l3.Num;
=======
select distinct p.num as ConsecutiveNums 
from Logs p, Logs q, Logs r
where
p.id = q.id - 1 and
q.id = r.id - 1 and
p.num = q.num and
q.num = r.num;

>>>>>>> develop
