CREATE TABLE Employee (
	EmployeeID INT PRIMARY KEY,
	FirstName VARCHAR(50),
	LastName VARCHAR(50),
	Department VARCHAR(50),
	Salary NUMERIC(10,2),
	HireDate DATE,
	City VARCHAR(50),
	Age INT,
	Gender CHAR(1)
);

INSERT INTO Employee(EmployeeID,FirstName,LastName,Department,Salary,HireDate,City,Age,Gender)
Values
(1, 'John', 'Doe', 'IT', 75000.00, '15-MAY-20', 'New York', 30, 'M'),
(2, 'Jane', 'Smith', 'HR', 68000.00, '22-AUG-18', 'Los Angeles', 28, 'F'),
(3, 'Mark', 'Brown', 'Finance', 85000.00, '10-NOV-18', 'Chicago', 35, 'M'),
(4, 'Emily', 'Davis', 'Marketing', 72000.00, '12-MAR-19', 'Houston', 32, 'F'),
(5, 'Michael', 'Wilson', 'IT', 78000.00, '18-JUL-21', 'San Francisco', 29, 'M'),
(6, 'Sarah', 'Johnson', 'Finance', 91000.00, '24-FEB-16', 'New York', 40, 'F'),
(7, 'Chris', 'Lee', 'HR', 60000.00, '10-JAN-22', 'Seattle', 26, 'M'),
(8, 'Anna', 'White', 'Marketing', 68000.00, '05-SEP-20', 'Denver', 31, 'F'),
(9, 'David', 'Hall', 'Finance', 95000.00, '30-JUN-15', 'Chicago', 45, 'M'),
(10, 'Laura', 'Green', 'IT', 72000.00, '01-APR-0', 'Austin', 25, 'F');

SELECT column_name, data_type, character_maximum_length
FROM information_schema.columns
WHERE table_name = 'Employee';

SELECT * FROM Employee

SELECT * FROM Employee 
WHERE Department='IT';

SELECT * FROM Employee
WHERE Salary>75000;

SELECT * FROM Employee
WHERE HireDate> '2020-01-01';

SELECT * FROM Employee
WHERE City='Chicago';

SELECT * FROM EmplOyee
WHERE Gender='M';


SELECT * FROM EmplOyee
WHERE Gender='F';
