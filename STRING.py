# Problem: A phrase is a palindrome if it reads the same forward and backward after removing non-alphanumeric characters.

def isPalindrome(s: str) -> bool:
    s = ''.join(ch.lower() for ch in s if ch.isalnum())
    return s == s[::-1]

print(isPalindrome("A man, a plan, a canal: Panama"))  # True
