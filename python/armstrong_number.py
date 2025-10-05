def is_armstrong(num):
    digits = str(num)
    power = len(digits)
    total = sum(int(d)**power for d in digits)
    return total == num

num = int(input("Enter number: "))
print("Armstrong number" if is_armstrong(num) else "Not an Armstrong number")
