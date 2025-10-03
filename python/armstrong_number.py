#armstrong number
n = int(input())

count = 0
temp = n 
while temp>0:
    temp=temp//10
    count += 1

temp2 = n
sum = 0
while temp2>0:
    digit = temp2%10
    sum += digit**count
    temp2 //= 10

print(sum==n)