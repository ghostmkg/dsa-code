/**
 * Edit Distance (Levenshtein Distance)
 * 
 * Description: Minimum number of operations (insert, delete, replace) required
 * to convert one string to another. Classic application of dynamic programming.
 * 
 * Time Complexity: O(m × n)
 * Space Complexity: O(m × n), optimizable to O(min(m,n))
 * 
 * Use Cases:
 * - Spell checkers and autocorrect
 * - DNA sequence analysis
 * - Plagiarism detection
 * - Natural language processing
 * 
 * Example:
 * Input: word1 = "horse", word2 = "ros"
 * Output: {distance: 3, operations: ["replace h->r", "delete r", "delete e"]}
 */

function editDistance(word1, word2) {
    // Input validation
    if (typeof word1 !== 'string' || typeof word2 !== 'string') {
        throw new Error('Invalid input: both arguments must be strings');
    }

    const m = word1.length;
    const n = word2.length;
    const dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

    // Initialize base cases
    for (let i = 0; i <= m; i++) dp[i][0] = i;
    for (let j = 0; j <= n; j++) dp[0][j] = j;

    // Fill DP table
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (word1[i - 1] === word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + Math.min(
                    dp[i - 1][j],     // Delete
                    dp[i][j - 1],     // Insert
                    dp[i - 1][j - 1]  // Replace
                );
            }
        }
    }

    // Backtrack to find operations
    const operations = [];
    let i = m, j = n;
    
    while (i > 0 || j > 0) {
        if (i === 0) {
            operations.unshift(`Insert '${word2[j - 1]}' at position ${i}`);
            j--;
        } else if (j === 0) {
            operations.unshift(`Delete '${word1[i - 1]}' at position ${i}`);
            i--;
        } else if (word1[i - 1] === word2[j - 1]) {
            i--;
            j--;
        } else {
            const deleteCost = dp[i - 1][j];
            const insertCost = dp[i][j - 1];
            const replaceCost = dp[i - 1][j - 1];
            const minCost = Math.min(deleteCost, insertCost, replaceCost);

            if (minCost === replaceCost) {
                operations.unshift(`Replace '${word1[i - 1]}' with '${word2[j - 1]}'`);
                i--;
                j--;
            } else if (minCost === deleteCost) {
                operations.unshift(`Delete '${word1[i - 1]}'`);
                i--;
            } else {
                operations.unshift(`Insert '${word2[j - 1]}'`);
                j--;
            }
        }
    }

    return {
        distance: dp[m][n],
        operations,
        dpTable: dp
    };
}

// Space-optimized version
function editDistanceOptimized(word1, word2) {
    const m = word1.length;
    const n = word2.length;
    
    let prev = Array.from({ length: n + 1 }, (_, i) => i);
    let curr = new Array(n + 1);

    for (let i = 1; i <= m; i++) {
        curr[0] = i;
        for (let j = 1; j <= n; j++) {
            if (word1[i - 1] === word2[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] = 1 + Math.min(prev[j], curr[j - 1], prev[j - 1]);
            }
        }
        [prev, curr] = [curr, prev];
    }

    return prev[n];
}

// Edit distance with custom costs
function editDistanceWithCosts(word1, word2, costs = { insert: 1, delete: 1, replace: 1 }) {
    const m = word1.length;
    const n = word2.length;
    const dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

    for (let i = 0; i <= m; i++) dp[i][0] = i * costs.delete;
    for (let j = 0; j <= n; j++) dp[0][j] = j * costs.insert;

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (word1[i - 1] === word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = Math.min(
                    dp[i - 1][j] + costs.delete,
                    dp[i][j - 1] + costs.insert,
                    dp[i - 1][j - 1] + costs.replace
                );
            }
        }
    }

    return dp[m][n];
}

// Similarity percentage based on edit distance
function similarityPercentage(word1, word2) {
    const distance = editDistanceOptimized(word1, word2);
    const maxLength = Math.max(word1.length, word2.length);
    return maxLength === 0 ? 100 : ((1 - distance / maxLength) * 100).toFixed(2);
}

// Find closest match from dictionary
function findClosestMatch(word, dictionary) {
    let minDistance = Infinity;
    let closestWord = null;

    for (let dictWord of dictionary) {
        const distance = editDistanceOptimized(word, dictWord);
        if (distance < minDistance) {
            minDistance = distance;
            closestWord = dictWord;
        }
    }

    return { word: closestWord, distance: minDistance };
}

// Test cases
const word1 = "horse";
const word2 = "ros";

const result = editDistance(word1, word2);
console.log('Edit distance:', result.distance); // 3
console.log('Operations:', result.operations);

console.log('Optimized:', editDistanceOptimized(word1, word2)); // 3

const customResult = editDistanceWithCosts("abc", "def", { 
    insert: 2, 
    delete: 3, 
    replace: 1 
});
console.log('Custom costs:', customResult); // 3

console.log('Similarity:', similarityPercentage("kitten", "sitting"), '%'); // 57.14%

const dictionary = ["apple", "application", "apply", "ape"];
console.log('Closest match:', findClosestMatch("appl", dictionary)); // {word: "apply", distance: 1}

module.exports = { 
    editDistance, 
    editDistanceOptimized, 
    editDistanceWithCosts,
    similarityPercentage,
    findClosestMatch
};
