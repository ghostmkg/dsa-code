# dice_roller.py
import random

def roll_dice():
    return random.randint(1, 6)

if __name__ == "__main__":
    while True:
        input("Press Enter to roll the dice...")
        print(f"You rolled a {roll_dice()}!")
        again = input("Roll again? (y/n): ").lower()
        if again != 'y':
            print("Thanks for playing!")
            break
            
