num1 = [1,2,3,0,0,0]
num2 = [2,5,6]
m = 3
n = 3
left = 0
right = 0
result = []
while left < m and right < n:
  if num1[left] < num2[right]:
    result.append(num1[left])
    left+=1
  else:
    result.append(num2[right])
    right+=1
while left < m:
  result.append(num1[left])
  left+=1
while right < n:
  result.append(num2[right])
  right+=1
for i in range(m+n):
  num1[i] = result[i]