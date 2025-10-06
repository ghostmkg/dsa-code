#  Minimum Window Substring

from collections import Counter

def minWindow(s: str, t: str) -> str:
    if not t or not s: 
        return ""
    need = Counter(t)
    missing = len(t)
    left = start = end = 0
    for right, ch in enumerate(s, 1):
        if need[ch] > 0:
            missing -= 1
        need[ch] -= 1
        if missing == 0:
            while left < right and need[s[left]] < 0:
                need[s[left]] += 1
                left += 1
            if end == 0 or right - left <= end - start:
                start, end = left, right
            need[s[left]] += 1
            missing += 1
            left += 1
    return s[start:end]

s = "ADOBECODEBANC"
t = "ABC"
print(minWindow(s, t))
