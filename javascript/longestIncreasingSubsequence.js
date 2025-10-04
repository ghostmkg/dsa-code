/**
 * Longest Increasing Subsequence (LIS)
 * 
 * Description: Finds the length of the longest strictly increasing subsequence
 * in an array. Multiple approaches: DP O(n²) and Binary Search O(n log n).
 * 
 * Time Complexity: O(n²) for DP, O(n log n) for optimized
 * Space Complexity: O(n)
 * 
 * Use Cases:
 * - Stock market analysis (longest profitable period)
 * - Patience sorting
 * - Box stacking problems
 * - Version control systems
 * 
 * Example:
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: {length: 4, lis: [2,3,7,18]}
 */

function longestIncreasingSubsequence(nums) {
    // Input validation
    if (!Array.isArray(nums) || nums.length === 0) {
        throw new Error('Invalid input: nums must be a non-empty array');
    }

    const n = nums.length;
    const dp = new Array(n).fill(1);
    const prev = new Array(n).fill(-1);
    let maxLength = 1;
    let maxIndex = 0;

    // DP approach
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
                
                if (dp[i] > maxLength) {
                    maxLength = dp[i];
                    maxIndex = i;
                }
            }
        }
    }

    // Reconstruct LIS
    const lis = [];
    let current = maxIndex;
    while (current !== -1) {
        lis.unshift(nums[current]);
        current = prev[current];
    }

    return {
        length: maxLength,
        lis,
        dp
    };
}

// Optimized O(n log n) solution using Binary Search
function lisOptimized(nums) {
    if (nums.length === 0) return { length: 0, lis: [] };

    const tails = [];
    const prev = new Array(nums.length).fill(-1);
    const indices = [];

    function binarySearch(arr, target) {
        let left = 0, right = arr.length - 1;
        while (left <= right) {
            const mid = Math.floor((left + right) / 2);
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    for (let i = 0; i < nums.length; i++) {
        const pos = binarySearch(tails, nums[i]);
        
        if (pos === tails.length) {
            tails.push(nums[i]);
            indices.push(i);
        } else {
            tails[pos] = nums[i];
            indices[pos] = i;
        }

        if (pos > 0) {
            prev[i] = indices[pos - 1];
        }
    }

    // Reconstruct LIS
    const lis = [];
    let current = indices[indices.length - 1];
    while (current !== -1) {
        lis.unshift(nums[current]);
        current = prev[current];
    }

    return {
        length: tails.length,
        lis
    };
}

// Number of LIS
function numberOfLIS(nums) {
    if (nums.length === 0) return 0;

    const n = nums.length;
    const lengths = new Array(n).fill(1);
    const counts = new Array(n).fill(1);
    let maxLength = 1;

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (lengths[j] + 1 > lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j];
                } else if (lengths[j] + 1 === lengths[i]) {
                    counts[i] += counts[j];
                }
            }
        }
        maxLength = Math.max(maxLength, lengths[i]);
    }

    let result = 0;
    for (let i = 0; i < n; i++) {
        if (lengths[i] === maxLength) {
            result += counts[i];
        }
    }

    return result;
}

// Longest Decreasing Subsequence
function longestDecreasingSubsequence(nums) {
    return longestIncreasingSubsequence(nums.map(x => -x));
}

// Longest Bitonic Subsequence
function longestBitonicSubsequence(nums) {
    const n = nums.length;
    const lis = new Array(n).fill(1);
    const lds = new Array(n).fill(1);

    // Calculate LIS for each position
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                lis[i] = Math.max(lis[i], lis[j] + 1);
            }
        }
    }

    // Calculate LDS from each position
    for (let i = n - 2; i >= 0; i--) {
        for (let j = n - 1; j > i; j--) {
            if (nums[j] < nums[i]) {
                lds[i] = Math.max(lds[i], lds[j] + 1);
            }
        }
    }

    let maxLength = 0;
    for (let i = 0; i < n; i++) {
        maxLength = Math.max(maxLength, lis[i] + lds[i] - 1);
    }

    return maxLength;
}

// Test cases
const nums = [10, 9, 2, 5, 3, 7, 101, 18];

const result = longestIncreasingSubsequence(nums);
console.log('LIS length:', result.length); // 4
console.log('LIS:', result.lis); // [2, 3, 7, 18]

const optimized = lisOptimized(nums);
console.log('Optimized LIS:', optimized); // {length: 4, lis: [2, 3, 7, 18]}

console.log('Number of LIS:', numberOfLIS([1,3,5,4,7])); // 2
console.log('Longest Bitonic:', longestBitonicSubsequence([1,11,2,10,4,5,2,1])); // 6

module.exports = { 
    longestIncreasingSubsequence, 
    lisOptimized, 
    numberOfLIS,
    longestDecreasingSubsequence,
    longestBitonicSubsequence
};
