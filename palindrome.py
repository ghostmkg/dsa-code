def is_palindrome(text):
    # Remove spaces and convert to lowercase for accurate comparison
    cleaned = ''.join(char.lower() for char in text if char.isalnum())
    return cleaned == cleaned[::-1]

print("Welcome to the Palindrome Checker!")
print("A palindrome is a word, number, or phrase that reads the same backward as forward.")
print("For example, 'Level', '12321', and 'A man a plan a canal Panama' are palindromes.")
print("---------------------------------------------------------------")

while True:
    user_input = input("Enter any word, number, or phrase to check (or type 'exit' to quit): ")

    if user_input.strip().lower() == 'exit':
        print("Thank you for using the Palindrome Checker. Goodbye!")
        break

    if is_palindrome(user_input):
        print(f"Yes! '{user_input}' is a palindrome.\n")
    else:
        print(f"No, '{user_input}' is not a palindrome.\n")

    print("---------------------------------------------------------------")
