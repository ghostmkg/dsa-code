x = 121
n = x
rev = 0
while n > 0:
  digit = n % 10
  rev = rev * 10 + digit
  n = n // 10
if x == rev:
  print("Number is Palindrome")
else:
  print("Number is not palindrome")