### Edit Distance  AKA ( Levenshtein Distance )
- Levenshtein distance is a measure of the similarity between two strings, which takes into account the number of insertion, deletion and substitution operations needed to transform one string into the other. 

**Problem statement:**
- Given two words word1 and word2, return the minimum number of operations required to convert word1 to word2.
  You have these operations permitted on a word:
   - Insert a character
   - Delete a character
   - Replace a character
 
- Example 1:
  Input: word1 = "horse", word2 = "ros"
  Output: 3  
  Explanation:
    horse → rorse (replace ‘h’ with ‘r’)  
    rorse → rose (remove ‘r’)  
    rose → ros (remove ‘e’)  

- Example 2:
  Input: word1 = "intention", word2 = "execution"
  Output: 5
  Explanation: 
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')
 
- Constraints:
  1 <= word1.length, word2.length <= 500  
  word1 and word2 consist of lowercase English letters.

**Approach:**
- Using dynamic programming.
- Defined dp[i][j] = min edits to convert first i chars of word1 to first j chars of word2.
- Recurrence:
  - If characters match, dp[i][j] = dp[i-1][j-1]
  - Else dp[i][j] = 1 + min(insert, delete, replace)
  
**Time Complexity:** O(n * m)  
**Space Complexity:** O(n * m) or O(min(n, m)) with optimization.

**Edge cases:**
- One or both strings empty
- Strings are already equal
