Employee = pd.DataFrame({
    'id': [1, 2, 3, 4],
    'name': ['Alice', 'Bob', 'Charlie', 'David'],
    'salary': [5000, 7000, 6000, 8000],
    'departmentId': [1, 1, 2, 2]
})
Department = pd.DataFrame({
    'id': [1, 2],
    'name': ['HR', 'Engineering']
})

merged = Employee.merge(Department, left_on='departmentId', right_on='id')
result = merged.groupby('name_y', as_index=False)['salary'].mean().rename(columns={'name_y': 'department'})
print(result)
