/**
 * Counting Sort
 * 
 * Description: Non-comparison based sorting algorithm that sorts integers by
 * counting the number of objects having distinct key values. Works best when
 * the range of input data is not significantly greater than the number of items.
 * 
 * Time Complexity: O(n + k) where k is the range
 * Space Complexity: O(k)
 * 
 * Use Cases:
 * - Sorting integers with small range
 * - As a subroutine in Radix Sort
 * - Sorting characters in a string
 * - When stability is required
 * 
 * Example:
 * Input: arr = [4,2,2,8,3,3,1]
 * Output: [1,2,2,3,3,4,8]
 */

function countingSort(arr, min = null, max = null) {
    // Input validation
    if (!Array.isArray(arr) || arr.length === 0) {
        return [];
    }

    // Find range if not provided
    if (min === null || max === null) {
        min = Math.min(...arr);
        max = Math.max(...arr);
    }

    const range = max - min + 1;
    const count = new Array(range).fill(0);
    const output = new Array(arr.length);

    // Count occurrences
    for (let num of arr) {
        count[num - min]++;
    }

    // Cumulative count
    for (let i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (stable sort - traverse from right)
    for (let i = arr.length - 1; i >= 0; i--) {
        const num = arr[i];
        output[count[num - min] - 1] = num;
        count[num - min]--;
    }

    return output;
}

// In-place version (not stable)
function countingSortInPlace(arr) {
    if (arr.length === 0) return arr;

    const min = Math.min(...arr);
    const max = Math.max(...arr);
    const range = max - min + 1;
    const count = new Array(range).fill(0);

    // Count occurrences
    for (let num of arr) {
        count[num - min]++;
    }

    // Overwrite original array
    let index = 0;
    for (let i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min;
            count[i]--;
        }
    }

    return arr;
}

// Counting sort for objects with key function
function countingSortWithKey(arr, keyFunc, min, max) {
    const range = max - min + 1;
    const count = new Array(range).fill(0);
    const output = new Array(arr.length);

    // Count occurrences
    for (let item of arr) {
        const key = keyFunc(item);
        count[key - min]++;
    }

    // Cumulative count
    for (let i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (stable)
    for (let i = arr.length - 1; i >= 0; i--) {
        const key = keyFunc(arr[i]);
        output[count[key - min] - 1] = arr[i];
        count[key - min]--;
    }

    return output;
}

// Sort characters in a string
function countingSortString(str) {
    const arr = str.split('');
    const min = 0;
    const max = 255; // ASCII range

    const count = new Array(max - min + 1).fill(0);

    for (let char of arr) {
        count[char.charCodeAt(0)]++;
    }

    let result = '';
    for (let i = 0; i < count.length; i++) {
        result += String.fromCharCode(i).repeat(count[i]);
    }

    return result;
}

// Count inversions using counting sort concept
function countInversions(arr) {
    const sorted = [...arr].sort((a, b) => a - b);
    const rank = new Map();
    sorted.forEach((val, idx) => rank.set(val, idx));

    let inversions = 0;
    const BIT = new Array(arr.length + 1).fill(0);

    function update(index, value) {
        while (index < BIT.length) {
            BIT[index] += value;
            index += index & (-index);
        }
    }

    function query(index) {
        let sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & (-index);
        }
        return sum;
    }

    for (let i = arr.length - 1; i >= 0; i--) {
        const r = rank.get(arr[i]) + 1;
        inversions += query(r - 1);
        update(r, 1);
    }

    return inversions;
}

// Sorting with negative numbers
function countingSortNegative(arr) {
    if (arr.length === 0) return [];

    const min = Math.min(...arr);
    const max = Math.max(...arr);

    return countingSort(arr, min, max);
}

// Performance comparison
function performanceTest(size, range) {
    const arr = Array.from({ length: size }, () => 
        Math.floor(Math.random() * range)
    );

    console.time('Counting Sort');
    countingSort([...arr]);
    console.timeEnd('Counting Sort');

    console.time('JavaScript Sort');
    [...arr].sort((a, b) => a - b);
    console.timeEnd('JavaScript Sort');
}

// Test cases
const arr = [4, 2, 2, 8, 3, 3, 1];

console.log('Sorted:', countingSort(arr)); // [1, 2, 2, 3, 3, 4, 8]
console.log('In-place:', countingSortInPlace([...arr])); // [1, 2, 2, 3, 3, 4, 8]

const objArr = [
    { name: 'Alice', age: 25 },
    { name: 'Bob', age: 22 },
    { name: 'Charlie', age: 25 },
    { name: 'David', age: 22 }
];
console.log('By age:', countingSortWithKey(objArr, obj => obj.age, 22, 25));

console.log('String sort:', countingSortString('dcba')); // 'abcd'
console.log('With negatives:', countingSortNegative([-5, -10, 0, -3, 8, 5, -1, 10]));

module.exports = { 
    countingSort, 
    countingSortInPlace, 
    countingSortWithKey,
    countingSortString,
    countInversions
};
