def manacher(s):
    # Preprocess string
    T = '#' + '#'.join(s) + '#'
    n = len(T)
    P = [0] * n  # Palindrome radius array
    C = 0  # Center of current palindrome
    R = 0  # Right boundary of current palindrome

    for i in range(n):
        mirr = 2*C - i  # Mirror of i around center C

        if i < R:
            P[i] = min(R - i, P[mirr])

        # Expand around center i
        a = i + P[i] + 1
        b = i - P[i] - 1
        while a < n and b >= 0 and T[a] == T[b]:
            P[i] += 1
            a += 1
            b -= 1

        # Update center and right boundary
        if i + P[i] > R:
            C = i
            R = i + P[i]

    # Find maximum palindrome
    max_len = max(P)
    center_index = P.index(max_len)
    start = (center_index - max_len)//2  # Index in original string
    longest_palindrome = s[start: start + max_len]
    return longest_palindrome

# Example usage
s = "babad"
print("Longest Palindromic Substring:", manacher(s))
