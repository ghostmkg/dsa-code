
a = 0
b = 1
c = 0
i = 0
arr = []
while True:
    c = a + b
    a = b
    b = c
    i += 1
    if c > 4000000:
        break
    if c % 2 == 0:
        arr.append(c)
sum_1 = 0
for i in range(len(arr)):
    sum_1 += int(arr[i])

print(len(arr))
print(sum_1)
