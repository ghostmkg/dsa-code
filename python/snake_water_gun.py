import time
import random

print("\033[95m                         !! WELCOME IN SNAKE WATER GUN !!\033[0m\n")
time.sleep(2)
print("\033[94mRules of the game\033[0m")
time.sleep(1)
print("1.There will be 5 rounds.")
time.sleep(1)
print("2.At the end, player with highest point win the game.")
time.sleep(1)
print("3.WIN  = 2 points")
print("  DRAW = 1 points each")
print("  LOSS = 0 points \n") 
time.sleep(2)
print("\033[96m                                    ! LET'S GO !            \033[0m\n")
time.sleep(2)

def start_game():
    print("List of weapons\n  snake\n  water\n  gun") 
    time.sleep(1)
    Player = 0
    Computer = 0
    i = 1
    while i<= 5 :
        number = random.choice(["snake","water","gun"]) 
       
        print("\033[93m                ********** ROUND", i ,"**********              \033[0m")    
        time.sleep(1)
        playerchoice = input("Choose your Weapon:")
        print("Computer Weapon:",number)
        if playerchoice == number :
            time.sleep(1)
            print("\033[94mMatch Draw\033[0m")
            Player = Player+1
            Computer = Computer+1
        elif playerchoice == "snake" and number == "water" :
            time.sleep(1)
            print("\033[92mYou WON\033[0m")
            Player = Player+2
        elif playerchoice == "snake" and number == "gun" :
            time.sleep(1)
            print("\033[91mYou LOSS\033[0m")
            Computer = Computer+2
        elif playerchoice == "water" and number == "snake" :
            time.sleep(1)
            print("\033[91mYou LOSS\033[0m")
            Computer = Computer+2
        elif playerchoice == "water" and number == "gun" :
            time.sleep(1)
            print("\033[92mYou WON\033[0m")
            Player = Player+2
        elif playerchoice == "gun" and number == "water" :
            time.sleep(1)
            print("\033[91mYou LOSS\033[0m")
            Computer = Computer+2
        elif playerchoice == "gun" and number == "snake" :
            time.sleep(1)
            print("\033[92mYou WON\033[0m")
            Player = Player+2
        else :
            time.sleep(1)
            print("Enter input in GIVEN ways")
        if i == 5 :
            print("          **********GAME OVER**********")
            print("Your Final Score:",Player)  
            print("Computer Final Score:",Computer) 
            time.sleep(2) 
            if Player > Computer:
                print("\033[92mCongratulations! You WIN the game 🎉\033[0m")
            elif Computer > Player:
                print("\033[91mSorry! You LOST the game 😢\033[0m")
            else:
                print("\033[93mIt's a TIE!\033[0m")
        i=i+1    

# --- Replay Option Added Below ---
while True:
    start_game()
    replay = input("\nDo you want to play again? (yes/no): ").strip().lower()
    if replay not in ["yes", "y"]:
        print("\nThanks for playing! 👋")
        break
