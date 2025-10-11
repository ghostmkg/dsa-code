select distinct p.num as ConsecutiveNums 
from Logs p, Logs q, Logs r
where
p.id = q.id - 1 and
q.id = r.id - 1 and
p.num = q.num and
q.num = r.num;

