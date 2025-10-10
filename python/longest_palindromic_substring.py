# longest_palindromic_substring.py
# Author: Garima Bisht
# This program finds the longest palindromic substring in a given string.

def longest_palindrome(s: str) -> str:
    if not s:
        return ""
    
    start = 0
    end = 0
    
    def expand_from_center(left: int, right: int) -> int:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1
    
    for i in range(len(s)):
        len1 = expand_from_center(i, i)      # Odd length palindrome
        len2 = expand_from_center(i, i + 1)  # Even length palindrome
        max_len = max(len1, len2)
        if max_len > end - start:
            start = i - (max_len - 1) // 2
            end = i + max_len // 2
    
    return s[start:end+1]

# Example usage
if __name__ == "__main__":
    test_string = "babad"
    result = longest_palindrome(test_string)
    print(f"Longest palindromic substring of '{test_string}' is: '{result}'")
