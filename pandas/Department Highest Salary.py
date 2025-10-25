Employee = pd.DataFrame({
    'id': [1, 2, 3, 4],
    'name': ['Alice', 'Bob', 'Charlie', 'David'],
    'salary': [5000, 7000, 6000, 7000],
    'departmentId': [1, 1, 2, 2]
})

Department = pd.DataFrame({
    'id': [1, 2],
    'name': ['HR', 'Engineering']
})

merged = Employee.merge(Department, left_on='departmentId', right_on='id', suffixes=('', '_dept'))
max_salary = merged.groupby('departmentId')['salary'].transform('max')
result = merged[merged['salary'] == max_salary][['name_dept', 'name', 'salary']]
print(result)
