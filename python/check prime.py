n=int(input("Enter a number to check if it is prime: "))
if n>1:
    for i in range(2,int(n/2)+1):
        if(n%i==0):
            print(f"{n} is not a prime number")
            break
    else:
        print(f"{n} is a prime number")
else:   
    print(f"{n}is not a prime number")