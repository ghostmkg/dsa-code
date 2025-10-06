select distinct p.email from person p, person q
where 
p.email = q.email and p.id > q.id;