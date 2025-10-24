Customers = pd.DataFrame({
    'id': [1, 2, 3],
    'name': ['Alice', 'Bob', 'Charlie']
})
Orders = pd.DataFrame({
    'id': [1, 2],
    'customerId': [1, 2]
})

merged = Customers.merge(Orders, left_on='id', right_on='customerId', how='left')
result = merged[merged['customerId'].isna()][['name']]
print(result)
