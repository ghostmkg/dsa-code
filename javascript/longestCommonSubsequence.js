/**
 * Longest Common Subsequence (LCS)
 * 
 * Description: Finds the longest subsequence common to two sequences. A subsequence
 * is a sequence derived from another by deleting some elements without changing the
 * order of remaining elements.
 * 
 * Time Complexity: O(m × n)
 * Space Complexity: O(m × n), optimizable to O(min(m,n))
 * 
 * Use Cases:
 * - DNA sequence alignment in bioinformatics
 * - File difference tools (diff, git)
 * - Plagiarism detection
 * - Data comparison and synchronization
 * 
 * Example:
 * Input: text1 = "ABCDGH", text2 = "AEDFHR"
 * Output: {length: 3, lcs: "ADH"}
 */

function longestCommonSubsequence(text1, text2) {
    // Input validation
    if (typeof text1 !== 'string' || typeof text2 !== 'string') {
        throw new Error('Invalid input: both arguments must be strings');
    }

    const m = text1.length;
    const n = text2.length;
    const dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

    // Build DP table
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (text1[i - 1] === text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the actual LCS
    let lcs = '';
    let i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] === text2[j - 1]) {
            lcs = text1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return {
        length: dp[m][n],
        lcs,
        dpTable: dp
    };
}

// Space-optimized version
function lcsOptimized(text1, text2) {
    const m = text1.length;
    const n = text2.length;
    
    let prev = new Array(n + 1).fill(0);
    let curr = new Array(n + 1).fill(0);

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (text1[i - 1] === text2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = Math.max(prev[j], curr[j - 1]);
            }
        }
        [prev, curr] = [curr, prev];
    }

    return prev[n];
}

// Find all LCS (there can be multiple)
function allLCS(text1, text2) {
    const m = text1.length;
    const n = text2.length;
    const dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (text1[i - 1] === text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    const results = new Set();

    function backtrack(i, j, current) {
        if (i === 0 || j === 0) {
            results.add(current);
            return;
        }

        if (text1[i - 1] === text2[j - 1]) {
            backtrack(i - 1, j - 1, text1[i - 1] + current);
        } else {
            if (dp[i - 1][j] >= dp[i][j - 1]) {
                backtrack(i - 1, j, current);
            }
            if (dp[i][j - 1] >= dp[i - 1][j]) {
                backtrack(i, j - 1, current);
            }
        }
    }

    backtrack(m, n, '');
    return Array.from(results);
}

// Longest Common Substring (contiguous)
function longestCommonSubstring(text1, text2) {
    const m = text1.length;
    const n = text2.length;
    const dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    
    let maxLength = 0;
    let endIndex = 0;

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (text1[i - 1] === text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            }
        }
    }

    const substring = text1.substring(endIndex - maxLength, endIndex);
    return { length: maxLength, substring };
}

// Test cases
const text1 = "ABCDGH";
const text2 = "AEDFHR";

const result = longestCommonSubsequence(text1, text2);
console.log('LCS length:', result.length); // 3
console.log('LCS:', result.lcs); // "ADH"

console.log('Optimized:', lcsOptimized(text1, text2)); // 3
console.log('All LCS:', allLCS(text1, text2)); // ["ADH"]

const substr = longestCommonSubstring("ABABC", "BABCA");
console.log('Longest common substring:', substr); // {length: 4, substring: "BABC"}

module.exports = { 
    longestCommonSubsequence, 
    lcsOptimized, 
    allLCS, 
    longestCommonSubstring 
};
