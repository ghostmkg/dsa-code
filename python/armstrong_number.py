# Armstrong Number Checker
# Hacktoberfest Contribution by <your_name>

def is_armstrong(num: int) -> bool:
   
    digits = list(map(int, str(num)))
    power = len(digits)
    return sum(d ** power for d in digits) == num


if __name__ == "__main__":
    number = int(input("Enter a number: "))
    if is_armstrong(number):
        print(f"{number} is an Armstrong number")
    else:
        print(f"{number} is not an Armstrong number")
