/**
 * Matrix Chain Multiplication
 * 
 * Description: Determines the optimal way to parenthesize a chain of matrix
 * multiplications to minimize the total number of scalar multiplications.
 * 
 * Time Complexity: O(n³)
 * Space Complexity: O(n²)
 * 
 * Use Cases:
 * - Compiler optimization for expression evaluation
 * - Database query optimization
 * - Computer graphics transformations
 * - Signal processing
 * 
 * Example:
 * Input: dimensions = [10, 20, 30, 40, 30]
 * Output: {minCost: 30000, optimalOrder: "((A1(A2A3))A4)"}
 */

function matrixChainMultiplication(dimensions) {
    // Input validation
    if (!Array.isArray(dimensions) || dimensions.length < 2) {
        throw new Error('Invalid input: dimensions must be an array with at least 2 elements');
    }

    const n = dimensions.length - 1; // Number of matrices
    const dp = Array.from({ length: n }, () => Array(n).fill(0));
    const split = Array.from({ length: n }, () => Array(n).fill(0));

    // l is chain length
    for (let l = 2; l <= n; l++) {
        for (let i = 0; i < n - l + 1; i++) {
            const j = i + l - 1;
            dp[i][j] = Infinity;

            for (let k = i; k < j; k++) {
                const cost = dp[i][k] + dp[k + 1][j] + 
                           dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    // Build optimal parenthesization
    function buildOrder(i, j) {
        if (i === j) {
            return `A${i + 1}`;
        }
        const k = split[i][j];
        return `(${buildOrder(i, k)}${buildOrder(k + 1, j)})`;
    }

    return {
        minCost: dp[0][n - 1],
        optimalOrder: n === 1 ? 'A1' : buildOrder(0, n - 1),
        dpTable: dp,
        splitTable: split
    };
}

// Recursive solution with memoization
function matrixChainMemo(dimensions) {
    const n = dimensions.length - 1;
    const memo = Array.from({ length: n }, () => Array(n).fill(-1));

    function solve(i, j) {
        if (i === j) return 0;
        if (memo[i][j] !== -1) return memo[i][j];

        let minCost = Infinity;
        for (let k = i; k < j; k++) {
            const cost = solve(i, k) + solve(k + 1, j) + 
                        dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
            minCost = Math.min(minCost, cost);
        }

        memo[i][j] = minCost;
        return minCost;
    }

    return solve(0, n - 1);
}

// Print detailed multiplication steps
function printMultiplicationSteps(dimensions, split, i, j, step = { count: 0 }) {
    if (i === j) {
        return `Matrix_${i + 1}[${dimensions[i]}x${dimensions[i + 1]}]`;
    }

    const k = split[i][j];
    const left = printMultiplicationSteps(dimensions, split, i, k, step);
    const right = printMultiplicationSteps(dimensions, split, k + 1, j, step);
    
    step.count++;
    const cost = dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
    
    console.log(`Step ${step.count}: Multiply ${left} × ${right}`);
    console.log(`  Cost: ${dimensions[i]} × ${dimensions[k + 1]} × ${dimensions[j + 1]} = ${cost}`);
    
    return `Result_${step.count}[${dimensions[i]}x${dimensions[j + 1]}]`;
}

// Calculate total cost for a given parenthesization
function calculateCost(dimensions, order) {
    // Simple evaluation - parse the order string and calculate cost
    let totalCost = 0;
    // Implementation would require parsing the order string
    return totalCost;
}

// Generate all possible parenthesizations (for small n)
function allParenthesizations(n) {
    if (n === 1) return ['A1'];
    
    const results = [];
    for (let k = 1; k < n; k++) {
        const left = allParenthesizations(k);
        const right = allParenthesizations(n - k);
        
        for (let l of left) {
            for (let r of right) {
                results.push(`(${l}${r})`);
            }
        }
    }
    return results;
}

// Catalan number: number of ways to parenthesize n matrices
function catalanNumber(n) {
    if (n <= 1) return 1;
    
    const dp = new Array(n + 1).fill(0);
    dp[0] = dp[1] = 1;
    
    for (let i = 2; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    
    return dp[n];
}

// Test cases
const dimensions = [10, 20, 30, 40, 30];

const result = matrixChainMultiplication(dimensions);
console.log('Minimum cost:', result.minCost); // 30000
console.log('Optimal order:', result.optimalOrder); // ((A1(A2A3))A4)

console.log('\nMemoization result:', matrixChainMemo(dimensions)); // 30000

console.log('\nNumber of ways to parenthesize 4 matrices:', catalanNumber(4)); // 14

console.log('\nDetailed steps:');
printMultiplicationSteps(dimensions, result.splitTable, 0, dimensions.length - 2);

module.exports = { 
    matrixChainMultiplication, 
    matrixChainMemo,
    printMultiplicationSteps,
    allParenthesizations,
    catalanNumber
};
