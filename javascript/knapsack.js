/**
 * 0/1 Knapsack Problem (Dynamic Programming)
 * 
 * Description: Given weights and values of n items, determine the maximum value that can
 * be obtained by selecting items with total weight not exceeding capacity. Each item can
 * be selected at most once.
 * 
 * Time Complexity: O(n × W) where W is capacity
 * Space Complexity: O(n × W), optimizable to O(W)
 * 
 * Use Cases:
 * - Resource allocation with budget constraints
 * - Portfolio optimization
 * - Cargo loading optimization
 * - Memory management in embedded systems
 * 
 * Example:
 * Input: values = [60,100,120], weights = [10,20,30], capacity = 50
 * Output: {maxValue: 220, items: [1,2]}
 */

function knapsack(values, weights, capacity) {
    // Input validation
    if (!Array.isArray(values) || !Array.isArray(weights) || values.length !== weights.length) {
        throw new Error('Invalid input: values and weights must be arrays of equal length');
    }
    if (!Number.isInteger(capacity) || capacity < 0) {
        throw new Error('Invalid capacity');
    }

    const n = values.length;
    const dp = Array.from({ length: n + 1 }, () => Array(capacity + 1).fill(0));

    // Build DP table
    for (let i = 1; i <= n; i++) {
        for (let w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = Math.max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find selected items
    const selectedItems = [];
    let w = capacity;
    for (let i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] !== dp[i - 1][w]) {
            selectedItems.push(i - 1);
            w -= weights[i - 1];
        }
    }

    return {
        maxValue: dp[n][capacity],
        items: selectedItems.reverse(),
        dpTable: dp
    };
}

// Space-optimized version using 1D array
function knapsackOptimized(values, weights, capacity) {
    const n = values.length;
    const dp = new Array(capacity + 1).fill(0);

    for (let i = 0; i < n; i++) {
        for (let w = capacity; w >= weights[i]; w--) {
            dp[w] = Math.max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }

    return dp[capacity];
}

// Unbounded Knapsack (items can be used multiple times)
function unboundedKnapsack(values, weights, capacity) {
    const dp = new Array(capacity + 1).fill(0);

    for (let w = 1; w <= capacity; w++) {
        for (let i = 0; i < values.length; i++) {
            if (weights[i] <= w) {
                dp[w] = Math.max(dp[w], values[i] + dp[w - weights[i]]);
            }
        }
    }

    return dp[capacity];
}

// Fractional Knapsack (greedy approach)
function fractionalKnapsack(values, weights, capacity) {
    const items = values.map((value, i) => ({
        value,
        weight: weights[i],
        ratio: value / weights[i],
        index: i
    }));

    items.sort((a, b) => b.ratio - a.ratio);

    let totalValue = 0;
    let remainingCapacity = capacity;
    const selected = [];

    for (let item of items) {
        if (remainingCapacity >= item.weight) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
            selected.push({ index: item.index, fraction: 1 });
        } else {
            const fraction = remainingCapacity / item.weight;
            totalValue += item.value * fraction;
            selected.push({ index: item.index, fraction });
            break;
        }
    }

    return { maxValue: totalValue, selected };
}

// Test cases
const values = [60, 100, 120];
const weights = [10, 20, 30];
const capacity = 50;

const result = knapsack(values, weights, capacity);
console.log('Max value:', result.maxValue); // 220
console.log('Selected items:', result.items); // [1, 2]

console.log('Optimized result:', knapsackOptimized(values, weights, capacity)); // 220
console.log('Unbounded result:', unboundedKnapsack(values, weights, capacity)); // 300
console.log('Fractional result:', fractionalKnapsack(values, weights, capacity)); // 240

module.exports = { knapsack, knapsackOptimized, unboundedKnapsack, fractionalKnapsack };
