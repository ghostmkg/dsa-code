def maxBalancedSubstring(s: str) -> int:
    balance = 0
    first_occurrence = {0: -1}  # balance -> first index
    max_len = 0
    
    for i, ch in enumerate(s):
        balance += 1 if ch == '1' else -1
        
        if balance in first_occurrence:
            max_len = max(max_len, i - first_occurrence[balance])
        else:
            first_occurrence[balance] = i
    
    return max_len

# Example test
if __name__ == "__main__":
    print(maxBalancedSubstring("11000111"))  # Output: 6
    print(maxBalancedSubstring("0011"))      # Output: 4
    print(maxBalancedSubstring("101010"))    # Output: 6
