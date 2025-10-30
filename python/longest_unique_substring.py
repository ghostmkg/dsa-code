def longestUniqueSubstring(s: str) -> int:
    seen = {}
    left = max_len = 0

    for right, ch in enumerate(s):
        if ch in seen and seen[ch] >= left:
            left = seen[ch] + 1
        seen[ch] = right
        max_len = max(max_len, right - left + 1)
    
    return max_len

# Example test
if __name__ == "__main__":
    print(longestUniqueSubstring("abcabcbb"))  # Output: 3
    print(longestUniqueSubstring("bbbbb"))     # Output: 1
    print(longestUniqueSubstring("pwwkew"))    # Output: 3
