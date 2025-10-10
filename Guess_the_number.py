import random

# Computer chooses a number between 1 and 10
number = random.randint(1, 10)

print("🎯 Welcome to the Guessing Game!")
print("I'm thinking of a number between 1 and 10.")

while True:
    guess = int(input("Enter your guess: "))
    if guess > number:
        print("Too high! Hint: Try a smaller number.")
    elif guess < number:
        print("Too low! Hint: Try a bigger number.")
    else:
        print("✅ Correct! You guessed the number!")
        break
