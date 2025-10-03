# Problem: Longest Substring Without Repeating Characters

## Difficulty

**Medium**

## Category

- Strings
- Sliding Window
- Hash Map

---

## Problem Statement

Given a string `s`, find the **length of the longest substring** without repeating characters.

---

## Input

- A string `s` consisting of English letters, digits, symbols, and spaces.
- `1 <= s.length <= 10^4`

---

## Output

- An integer representing the **length of the longest substring without repeating characters**.

---

## Examples

### Example 1:

- **Input:** `"abcabcbb"`
- **Output:** `3`
- **Explanation:** The answer is `"abc"`, with the length of 3.

### Example 2:

- **Input:** `"bbbbb"`
- **Output:** `1`
- **Explanation:** The answer is `"b"`, with the length of 1.

### Example 3:

- **Input:** `"pwwkew"`
- **Output:** `3`
- **Explanation:** The answer is `"wke"`, with the length of 3.

---

## Usage

```javascript
console.log(lengthOfLongestSubstring("abcabcbb")); // 3
console.log(lengthOfLongestSubstring("bbbbb")); // 1
console.log(lengthOfLongestSubstring("pwwkew")); // 3
console.log(lengthOfLongestSubstring("")); // 0
```
