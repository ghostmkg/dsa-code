def longest_palindromic_subsequence(s: str) -> int:
    n = len(s)
    # dp[i][j] = length of longest palindromic subsequence in s[i..j]
    dp = [[0] * n for _ in range(n)]

    # Base case: single letters are palindromes of length 1
    for i in range(n):
        dp[i][i] = 1

    # Build the table in bottom-up manner
    for length in range(2, n+1):  # substring lengths
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j]:
                if length == 2:
                    dp[i][j] = 2
                else:
                    dp[i][j] = dp[i+1][j-1] + 2
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])

    return dp[0][n-1]

# Example usage
if __name__ == "__main__":
    s = input("Enter string: ").strip()
    length = longest_palindromic_subsequence(s)
    print(f"Length of longest palindromic subsequence: {length}")
