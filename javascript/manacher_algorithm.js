/**
 * Manacher's Algorithm Implementation
 * 
 * Problem: Longest Palindromic Substring
 * Source: Classic String Algorithm
 * Approach: Expand Around Centers with Optimization
 * Time Complexity: O(n) where n is string length
 * Space Complexity: O(n) for radius array
 * 
 * Manacher's algorithm finds the longest palindromic substring in linear time
 * by using information from previously computed palindromes.
 */

class ManacherAlgorithm {
    constructor() {
        this.radius = [];
        this.center = 0;
        this.right = 0;
    }

    /**
     * Preprocess string by adding separators to handle even-length palindromes
     * @param {string} s - Input string
     * @returns {string} Processed string with separators
     */
    preprocess(s) {
        if (s.length === 0) return "^$";
        let processed = "^";
        for (let i = 0; i < s.length; i++) {
            processed += "#" + s[i];
        }
        processed += "#$";
        return processed;
    }

    /**
     * Find longest palindromic substring using Manacher's algorithm
     * @param {string} s - Input string
     * @returns {string} Longest palindromic substring
     */
    longestPalindrome(s) {
        if (!s || s.length === 0) return "";
        if (s.length === 1) return s;

        const processed = this.preprocess(s);
        const n = processed.length;
        this.radius = new Array(n).fill(0);
        
        this.center = 0;
        this.right = 0;
        let maxLen = 0;
        let centerIndex = 0;

        for (let i = 1; i < n - 1; i++) {
            // Mirror position
            const mirror = 2 * this.center - i;

            // If i is within the right boundary, use mirror information
            if (i < this.right) {
                this.radius[i] = Math.min(this.right - i, this.radius[mirror]);
            }

            // Try to expand palindrome centered at i
            try {
                while (processed[i + (1 + this.radius[i])] === 
                       processed[i - (1 + this.radius[i])]) {
                    this.radius[i]++;
                }
            } catch (e) {
                // Handle boundary cases
            }

            // Update center and right boundary if we found a longer palindrome
            if (i + this.radius[i] > this.right) {
                this.center = i;
                this.right = i + this.radius[i];
            }

            // Update maximum length and center index
            if (this.radius[i] > maxLen) {
                maxLen = this.radius[i];
                centerIndex = i;
            }
        }

        // Extract the longest palindromic substring
        const start = Math.floor((centerIndex - maxLen) / 2);
        return s.substring(start, start + maxLen);
    }

    /**
     * Find all palindromic substrings using Manacher's algorithm
     * @param {string} s - Input string
     * @returns {Array} Array of all palindromic substrings with their positions
     */
    findAllPalindromes(s) {
        if (!s || s.length === 0) return [];

        const processed = this.preprocess(s);
        const n = processed.length;
        this.radius = new Array(n).fill(0);
        
        this.center = 0;
        this.right = 0;
        const palindromes = [];

        for (let i = 1; i < n - 1; i++) {
            const mirror = 2 * this.center - i;

            if (i < this.right) {
                this.radius[i] = Math.min(this.right - i, this.radius[mirror]);
            }

            try {
                while (processed[i + (1 + this.radius[i])] === 
                       processed[i - (1 + this.radius[i])]) {
                    this.radius[i]++;
                }
            } catch (e) {
                // Handle boundary cases
            }

            if (i + this.radius[i] > this.right) {
                this.center = i;
                this.right = i + this.radius[i];
            }

            // Add palindrome if it has length > 1
            if (this.radius[i] > 0) {
                const start = Math.floor((i - this.radius[i]) / 2);
                const length = this.radius[i];
                const palindrome = s.substring(start, start + length);
                
                palindromes.push({
                    substring: palindrome,
                    start: start,
                    end: start + length - 1,
                    length: length
                });
            }
        }

        // Remove duplicates and sort by length
        const uniquePalindromes = palindromes.filter((p, index, self) => 
            index === self.findIndex(pp => 
                pp.start === p.start && pp.end === p.end
            )
        );

        return uniquePalindromes.sort((a, b) => b.length - a.length);
    }

    /**
     * Check if a string is a palindrome
     * @param {string} s - Input string
     * @returns {boolean} True if palindrome, false otherwise
     */
    isPalindrome(s) {
        if (!s || s.length === 0) return true;
        
        let left = 0;
        let right = s.length - 1;
        
        while (left < right) {
            if (s[left] !== s[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }

    /**
     * Count the number of palindromic substrings
     * @param {string} s - Input string
     * @returns {number} Number of palindromic substrings
     */
    countPalindromes(s) {
        if (!s || s.length === 0) return 0;
        if (s.length === 1) return 1;

        const processed = this.preprocess(s);
        const n = processed.length;
        this.radius = new Array(n).fill(0);
        
        this.center = 0;
        this.right = 0;
        let count = 0;

        for (let i = 1; i < n - 1; i++) {
            const mirror = 2 * this.center - i;

            if (i < this.right) {
                this.radius[i] = Math.min(this.right - i, this.radius[mirror]);
            }

            try {
                while (processed[i + (1 + this.radius[i])] === 
                       processed[i - (1 + this.radius[i])]) {
                    this.radius[i]++;
                }
            } catch (e) {
                // Handle boundary cases
            }

            if (i + this.radius[i] > this.right) {
                this.center = i;
                this.right = i + this.radius[i];
            }

            // Count palindromes centered at position i
            count += Math.ceil(this.radius[i] / 2);
        }

        return count;
    }

    /**
     * Find the longest palindromic subsequence length (not substring)
     * @param {string} s - Input string
     * @returns {number} Length of longest palindromic subsequence
     */
    longestPalindromicSubsequence(s) {
        if (!s || s.length === 0) return 0;
        if (s.length === 1) return 1;

        const n = s.length;
        const dp = Array(n).fill().map(() => Array(n).fill(0));

        // Single characters are palindromes of length 1
        for (let i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Fill the DP table
        for (let len = 2; len <= n; len++) {
            for (let i = 0; i <= n - len; i++) {
                const j = i + len - 1;
                
                if (s[i] === s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }

    /**
     * Visualize the Manacher's algorithm process
     * @param {string} s - Input string
     */
    visualize(s) {
        console.log(`\n=== Manacher's Algorithm Visualization ===`);
        console.log(`Input: "${s}"`);
        
        const processed = this.preprocess(s);
        console.log(`Processed: "${processed}"`);
        
        const longest = this.longestPalindrome(s);
        console.log(`Longest Palindrome: "${longest}"`);
        
        const count = this.countPalindromes(s);
        console.log(`Total Palindromes: ${count}`);
        
        const allPalindromes = this.findAllPalindromes(s);
        console.log(`All Palindromes:`);
        allPalindromes.forEach((p, index) => {
            console.log(`  ${index + 1}. "${p.substring}" (pos: ${p.start}-${p.end}, len: ${p.length})`);
        });
    }
}

// Utility functions for additional palindrome operations
class PalindromeUtils {
    /**
     * Check if a string can be rearranged to form a palindrome
     * @param {string} s - Input string
     * @returns {boolean} True if can be rearranged to palindrome
     */
    static canFormPalindrome(s) {
        const charCount = {};
        
        // Count character frequencies
        for (let char of s) {
            charCount[char] = (charCount[char] || 0) + 1;
        }
        
        // Count odd frequencies
        let oddCount = 0;
        for (let count of Object.values(charCount)) {
            if (count % 2 === 1) {
                oddCount++;
            }
        }
        
        // Can form palindrome if at most one character has odd frequency
        return oddCount <= 1;
    }

    /**
     * Find the minimum number of characters to add to make a string palindrome
     * @param {string} s - Input string
     * @returns {number} Minimum characters to add
     */
    static minAddToMakePalindrome(s) {
        if (!s || s.length === 0) return 0;
        
        const manacher = new ManacherAlgorithm();
        const longest = manacher.longestPalindrome(s);
        
        return s.length - longest.length;
    }

    /**
     * Check if a string is a palindrome ignoring case and non-alphanumeric characters
     * @param {string} s - Input string
     * @returns {boolean} True if palindrome
     */
    static isPalindromeIgnoreCase(s) {
        if (!s) return true;
        
        // Remove non-alphanumeric characters and convert to lowercase
        const cleaned = s.replace(/[^a-zA-Z0-9]/g, '').toLowerCase();
        
        let left = 0;
        let right = cleaned.length - 1;
        
        while (left < right) {
            if (cleaned[left] !== cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
}

// Demo function
function main() {
    console.log("=== Manacher's Algorithm for Longest Palindromic Substring ===\n");
    
    const manacher = new ManacherAlgorithm();
    
    // Test cases
    const testCases = [
        "babad",
        "cbbd",
        "a",
        "ac",
        "racecar",
        "abacabad",
        "abcdef",
        "aabbaa",
        "malayalam",
        "abccba",
        "abcdcba",
        "noon",
        "level",
        "rotator",
        "deified",
        "civic",
        "radar",
        "refer",
        "redder",
        "reviver",
        "rotator",
        "sagas",
        "solos",
        "stats",
        "tenet",
        "wow",
        "wowow",
        "wowowow",
        "abacaba",
        "abacabadabacaba",
        "abacabadabacabacabadabacaba",
        "",
        "a",
        "aa",
        "aaa",
        "aaaa",
        "aaaaa"
    ];
    
    testCases.forEach((testCase, index) => {
        console.log(`Test Case ${index + 1}: "${testCase}"`);
        
        const longest = manacher.longestPalindrome(testCase);
        const count = manacher.countPalindromes(testCase);
        const lps = manacher.longestPalindromicSubsequence(testCase);
        
        console.log(`  Longest Palindrome: "${longest}"`);
        console.log(`  Total Palindromes: ${count}`);
        console.log(`  Longest Palindromic Subsequence: ${lps}`);
        console.log(`  Can Form Palindrome: ${PalindromeUtils.canFormPalindrome(testCase)}`);
        console.log(`  Min Add to Make Palindrome: ${PalindromeUtils.minAddToMakePalindrome(testCase)}`);
        console.log(`  Palindrome (ignore case): ${PalindromeUtils.isPalindromeIgnoreCase(testCase)}`);
        console.log("-".repeat(60));
    });
    
    // Detailed visualization for interesting cases
    const interestingCases = ["babad", "abacabad", "racecar", "malayalam"];
    
    interestingCases.forEach(testCase => {
        manacher.visualize(testCase);
    });
    
    // Performance test
    console.log("\n=== Performance Test ===");
    const largeString = "a".repeat(1000) + "b" + "a".repeat(1000);
    
    console.log(`Testing with large string (length: ${largeString.length})`);
    
    const startTime = performance.now();
    const result = manacher.longestPalindrome(largeString);
    const endTime = performance.now();
    
    console.log(`Longest palindrome: "${result}"`);
    console.log(`Time taken: ${(endTime - startTime).toFixed(4)} ms`);
    
    // Advanced features
    console.log("\n=== Advanced Features ===");
    const advancedTest = "abacabadabacaba";
    const allPalindromes = manacher.findAllPalindromes(advancedTest);
    
    console.log(`All palindromes in "${advancedTest}":`);
    allPalindromes.forEach((p, index) => {
        console.log(`  ${index + 1}. "${p.substring}" at position ${p.start}-${p.end} (length: ${p.length})`);
    });
}

// Run the demo
main();
