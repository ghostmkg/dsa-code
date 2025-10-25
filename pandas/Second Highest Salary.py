Employee = pd.DataFrame({
    'id': [1, 2, 3],
    'salary': [100, 200, 300]
})
second_highest = Employee['salary'].drop_duplicates().nlargest(2).min()
print(second_highest)
