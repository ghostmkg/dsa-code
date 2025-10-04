/**
 * Quick Select Algorithm
 * 
 * Description: Finds the kth smallest element in an unsorted array using
 * a partition-based selection algorithm similar to QuickSort.
 * 
 * Time Complexity: O(n) average, O(n²) worst case
 * Space Complexity: O(1)
 * 
 * Use Cases:
 * - Finding median in streaming data
 * - Top-K problems without full sorting
 * - Percentile calculations
 * - Order statistics
 * 
 * Example:
 * Input: arr = [7,10,4,3,20,15], k = 3
 * Output: 7 (3rd smallest element)
 */

function quickSelect(arr, k) {
    // Input validation
    if (!Array.isArray(arr) || arr.length === 0) {
        throw new Error('Invalid input: array must be non-empty');
    }
    if (k < 1 || k > arr.length) {
        throw new Error(`Invalid k: must be between 1 and ${arr.length}`);
    }

    const nums = [...arr]; // Create copy to avoid mutation
    return quickSelectHelper(nums, 0, nums.length - 1, k - 1);
}

function quickSelectHelper(nums, left, right, k) {
    if (left === right) return nums[left];

    // Randomized partition for better average performance
    const pivotIndex = partition(nums, left, right);

    if (k === pivotIndex) {
        return nums[k];
    } else if (k < pivotIndex) {
        return quickSelectHelper(nums, left, pivotIndex - 1, k);
    } else {
        return quickSelectHelper(nums, pivotIndex + 1, right, k);
    }
}

function partition(nums, left, right) {
    // Random pivot selection
    const randomIndex = left + Math.floor(Math.random() * (right - left + 1));
    [nums[randomIndex], nums[right]] = [nums[right], nums[randomIndex]];

    const pivot = nums[right];
    let i = left;

    for (let j = left; j < right; j++) {
        if (nums[j] < pivot) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            i++;
        }
    }

    [nums[i], nums[right]] = [nums[right], nums[i]];
    return i;
}

// Find kth largest element
function quickSelectLargest(arr, k) {
    return quickSelect(arr, arr.length - k + 1);
}

// Find median
function findMedian(arr) {
    const n = arr.length;
    if (n % 2 === 1) {
        return quickSelect(arr, Math.floor(n / 2) + 1);
    } else {
        const mid1 = quickSelect(arr, n / 2);
        const mid2 = quickSelect(arr, n / 2 + 1);
        return (mid1 + mid2) / 2;
    }
}

// Find multiple order statistics efficiently
function findMultipleOrderStats(arr, positions) {
    const sorted = [...arr].sort((a, b) => a - b);
    return positions.map(k => sorted[k - 1]);
}

// Median of medians (guaranteed O(n) worst case)
function medianOfMedians(arr, k) {
    if (arr.length <= 5) {
        const sorted = [...arr].sort((a, b) => a - b);
        return sorted[k];
    }

    // Divide into groups of 5
    const medians = [];
    for (let i = 0; i < arr.length; i += 5) {
        const group = arr.slice(i, Math.min(i + 5, arr.length));
        const sorted = group.sort((a, b) => a - b);
        medians.push(sorted[Math.floor(sorted.length / 2)]);
    }

    const medianOfMed = medianOfMedians(medians, Math.floor(medians.length / 2));
    
    const left = arr.filter(x => x < medianOfMed);
    const equal = arr.filter(x => x === medianOfMed);
    const right = arr.filter(x => x > medianOfMed);

    if (k < left.length) {
        return medianOfMedians(left, k);
    } else if (k < left.length + equal.length) {
        return medianOfMed;
    } else {
        return medianOfMedians(right, k - left.length - equal.length);
    }
}

// Find top K elements
function topKElements(arr, k) {
    if (k >= arr.length) return [...arr];
    
    const result = [];
    const nums = [...arr];
    
    for (let i = 0; i < k; i++) {
        const kthSmallest = quickSelectHelper(nums, i, nums.length - 1, nums.length - k + i);
        result.push(kthSmallest);
    }
    
    return result;
}

// Top K frequent elements
function topKFrequent(arr, k) {
    const freqMap = new Map();
    for (let num of arr) {
        freqMap.set(num, (freqMap.get(num) || 0) + 1);
    }

    const unique = Array.from(freqMap.keys());
    const n = unique.length;
    
    quickSelectHelper(unique, 0, n - 1, n - k);
    
    return unique.slice(n - k).sort((a, b) => freqMap.get(b) - freqMap.get(a));
}

// Test cases
const arr = [7, 10, 4, 3, 20, 15];

console.log('3rd smallest:', quickSelect(arr, 3)); // 7
console.log('2nd largest:', quickSelectLargest(arr, 2)); // 15
console.log('Median:', findMedian(arr)); // 8.5
console.log('Top 3 elements:', topKElements(arr, 3)); // [15, 20, 10]

const freqArr = [1,1,1,2,2,3];
console.log('Top 2 frequent:', topKFrequent(freqArr, 2)); // [1, 2]

module.exports = { 
    quickSelect, 
    quickSelectLargest, 
    findMedian, 
    medianOfMedians,
    topKElements,
    topKFrequent
};
