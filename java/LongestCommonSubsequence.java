/*
Longest Common Subsequence (LCS) :- https://leetcode.com/problems/longest-common-subsequence/description/

Problem Statement:
Given two strings text1 and text2, return the length of their longest common subsequence. 
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
A common subsequence of two strings is a subsequence that is common to both strings.
If there is no common subsequence, return 0.

Examples:
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Input: text1 = "abc", text2 = "def"
Output: 0

Algorithm Description:
This algorithm computes the length of the longest common subsequence between two strings using dynamic programming. 
It builds a 2D table where each cell dp[i][j] represents the length of the LCS of the first i characters of text1 and the first j characters of text2.
If the current characters match, the LCS length increases by 1; otherwise, it takes the maximum from skipping a character from either string.

Use Cases:
- Comparing DNA, RNA, or protein sequences in bioinformatics
- File or version comparison tools (diff utilities)
- Text similarity and plagiarism detection

Time Complexity: O(n*m)
- Where n and m are the lengths of the two input strings. Each cell in the dp table is filled once.

Space Complexity: O(n*m)
- The dp table of size (n+1) x (m+1) is used to store intermediate results.
*/

public class LongestCommonSubsequence {
    public static void main(String[] args) {
        String s = "abcde", t = "ace";
        LongestCommonSubsequence lcs = new LongestCommonSubsequence();
        System.out.println(lcs.longestCommonSubsequence(s, t)); // Output: 3

        // Additional test cases
        System.out.println(lcs.longestCommonSubsequence("abc", "abc")); // Output: 3
        System.out.println(lcs.longestCommonSubsequence("abc", "def")); // Output: 0
        System.out.println(lcs.longestCommonSubsequence("", "abc"));    // Output: 0 (edge case: empty string)
        System.out.println(lcs.longestCommonSubsequence("abc", ""));    // Output: 0 (edge case: empty string)
    }

    /**
     * Calculates the length of the longest common subsequence between two strings.
     * @param s First input string
     * @param t Second input string
     * @return  Length of the longest common subsequence
     */
    public int longestCommonSubsequence(String s, String t) {
        int n = s.length(), m = t.length();
        int[][] dp = new int[n+1][m+1];

        // Build the dp table bottom-up
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s.charAt(i-1) == t.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1]; // Characters match, extend LCS
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]); // Skip one character from either string
                }
            }
        }
        return dp[n][m];
    }
}
