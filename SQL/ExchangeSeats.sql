select
case
when id % 2 = 1 and id + 1 <= (select max(id) from Seat) then id + 1
when id % 2 = 0 then id - 1
else id
end 
as id, student from Seat order by id
