/*
Longest Palindromic Subsequence

Problem Statement:
Given a string s, find the length of its longest palindromic subsequence. 
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
A palindromic subsequence is a subsequence that reads the same forward and backward.

Examples:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

Algorithm Description:
This algorithm computes the length of the longest palindromic subsequence in a string using dynamic programming. 
It leverages the fact that the longest palindromic subsequence of a string s is the same as the longest common subsequence (LCS) between s and its reverse.
A 2D DP table is constructed where dp[i][j] represents the length of the LCS between the first i characters of s and the first j characters of its reverse.
If the characters match, the LCS length increases by 1; otherwise, it takes the maximum from skipping a character from either string.

Use Cases:
- DNA/RNA sequence analysis for palindromic patterns
- Text analysis and pattern recognition
- Data compression and error correction

Time Complexity: O(n^2)
- Where n is the length of the input string. Each cell in the dp table is filled once.

Space Complexity: O(n^2)
- The dp table of size (n+1) x (n+1) is used to store intermediate results.
*/

public class LongestPalindromicSubsequence {
    public static void main(String[] args) {
        String s = "bbbab";
        LongestPalindromicSubsequence lps = new LongestPalindromicSubsequence();
        System.out.println(lps.longestPalindromeSubseq(s)); // Output: 4

        // Additional test cases
        System.out.println(lps.longestPalindromeSubseq("cbbd")); // Output: 2
        System.out.println(lps.longestPalindromeSubseq("a"));    // Output: 1 (single character)
        System.out.println(lps.longestPalindromeSubseq("abcde")); // Output: 1 (no repeating characters)
        System.out.println(lps.longestPalindromeSubseq(""));     // Output: 0 (empty string)
    }

    /**
     * Calculates the length of the longest palindromic subsequence in a string.
     * Uses the LCS approach between the string and its reverse.
     * @param s Input string
     * @return  Length of the longest palindromic subsequence
     */
    public int longestPalindromeSubseq(String s) {
        String t = new StringBuilder(s).reverse().toString(); // Reverse of s
        int n = s.length();
        int[][] dp = new int[n+1][n+1]; // dp[i][j]: LCS length for s[0..i-1] and t[0..j-1]

        // Build the dp table bottom-up
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s.charAt(i-1) == t.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1]; // Characters match, extend LCS
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]); // Skip one character from either string
                }
            }
        }
        return dp[n][n];
    }
}
