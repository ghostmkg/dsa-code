CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
set N=N-1;
  RETURN (
    select distinct Salary from Employee order by Salary desc limit N, 1
  );
END