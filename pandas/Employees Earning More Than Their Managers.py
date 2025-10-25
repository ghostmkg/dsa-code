import pandas as pd

data = {
    'id': [1, 2, 3, 4],
    'name': ['Alice', 'Bob', 'Charlie', 'David'],
    'salary': [5000, 7000, 6000, 8000],
    'managerId': [None, 1, 1, 2]
}
Employee = pd.DataFrame(data)

df = Employee.merge(Employee, left_on='managerId', right_on='id', suffixes=('', '_manager'))
result = df[df['salary'] > df['salary_manager']][['name']]
print(result)
