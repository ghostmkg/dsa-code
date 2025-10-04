/**
 * Radix Sort (LSD - Least Significant Digit)
 * 
 * Description: Non-comparison sorting algorithm that sorts integers by processing
 * individual digits. Uses counting sort as a subroutine for each digit position.
 * 
 * Time Complexity: O(d × (n + k)) where d is number of digits, k is base
 * Space Complexity: O(n + k)
 * 
 * Use Cases:
 * - Sorting large integers efficiently
 * - Sorting strings of equal length
 * - External sorting with limited memory
 * - Parallel sorting algorithms
 * 
 * Example:
 * Input: arr = [170, 45, 75, 90, 802, 24, 2, 66]
 * Output: [2, 24, 45, 66, 75, 90, 170, 802]
 */

function radixSort(arr, base = 10) {
    // Input validation
    if (!Array.isArray(arr) || arr.length === 0) {
        return [];
    }

    // Handle negative numbers
    const hasNegative = arr.some(num => num < 0);
    if (hasNegative) {
        return radixSortWithNegatives(arr, base);
    }

    const max = Math.max(...arr);
    const maxDigits = Math.floor(Math.log(max) / Math.log(base)) + 1;

    let result = [...arr];

    for (let digit = 0; digit < maxDigits; digit++) {
        result = countingSortByDigit(result, digit, base);
    }

    return result;
}

function countingSortByDigit(arr, digitPos, base) {
    const n = arr.length;
    const output = new Array(n);
    const count = new Array(base).fill(0);

    // Get digit at position
    const getDigit = (num, pos, base) => {
        return Math.floor(num / Math.pow(base, pos)) % base;
    };

    // Count occurrences
    for (let num of arr) {
        const digit = getDigit(num, digitPos, base);
        count[digit]++;
    }

    // Cumulative count
    for (let i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (stable sort)
    for (let i = n - 1; i >= 0; i--) {
        const digit = getDigit(arr[i], digitPos, base);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    return output;
}

// Radix sort with negative numbers
function radixSortWithNegatives(arr, base = 10) {
    const negative = arr.filter(x => x < 0).map(x => -x);
    const positive = arr.filter(x => x >= 0);

    const sortedNegative = radixSort(negative, base).reverse().map(x => -x);
    const sortedPositive = radixSort(positive, base);

    return [...sortedNegative, ...sortedPositive];
}

// MSD (Most Significant Digit) Radix Sort
function radixSortMSD(arr, base = 10) {
    if (arr.length <= 1) return arr;

    const max = Math.max(...arr.map(Math.abs));
    const maxDigits = Math.floor(Math.log(max) / Math.log(base)) + 1;

    function msdSort(arr, digit, base) {
        if (arr.length <= 1 || digit < 0) return arr;

        const buckets = Array.from({ length: base }, () => []);
        
        for (let num of arr) {
            const d = Math.floor(num / Math.pow(base, digit)) % base;
            buckets[d].push(num);
        }

        const result = [];
        for (let bucket of buckets) {
            result.push(...msdSort(bucket, digit - 1, base));
        }

        return result;
    }

    return msdSort(arr, maxDigits - 1, base);
}

// Radix sort for strings
function radixSortStrings(arr) {
    if (arr.length === 0) return [];

    const maxLen = Math.max(...arr.map(s => s.length));
    let result = [...arr];

    // Sort from rightmost character to leftmost
    for (let pos = maxLen - 1; pos >= 0; pos--) {
        result = countingSortStringsByChar(result, pos);
    }

    return result;
}

function countingSortStringsByChar(arr, charPos) {
    const buckets = Array.from({ length: 256 }, () => []);

    for (let str of arr) {
        const charCode = charPos < str.length ? str.charCodeAt(charPos) : 0;
        buckets[charCode].push(str);
    }

    return buckets.flat();
}

// Radix sort for floating point numbers
function radixSortFloat(arr, precision = 2) {
    const multiplier = Math.pow(10, precision);
    const integers = arr.map(x => Math.round(x * multiplier));
    const sorted = radixSortWithNegatives(integers);
    return sorted.map(x => x / multiplier);
}

// In-place radix sort (uses less memory)
function radixSortInPlace(arr, base = 10) {
    const max = Math.max(...arr);
    const maxDigits = Math.floor(Math.log(max) / Math.log(base)) + 1;

    for (let digit = 0; digit < maxDigits; digit++) {
        const buckets = Array.from({ length: base }, () => []);
        
        for (let num of arr) {
            const d = Math.floor(num / Math.pow(base, digit)) % base;
            buckets[d].push(num);
        }

        let index = 0;
        for (let bucket of buckets) {
            for (let num of bucket) {
                arr[index++] = num;
            }
        }
    }

    return arr;
}

// Radix sort with different bases comparison
function compareRadixBases(arr) {
    const bases = [2, 8, 10, 16];
    const results = {};

    for (let base of bases) {
        const start = performance.now();
        radixSort([...arr], base);
        const end = performance.now();
        results[`base-${base}`] = (end - start).toFixed(3) + 'ms';
    }

    return results;
}

// Count sort for specific digit (helper)
function getMaxDigits(arr, base) {
    const max = Math.max(...arr);
    return Math.floor(Math.log(max) / Math.log(base)) + 1;
}

// Test cases
const arr = [170, 45, 75, 90, 802, 24, 2, 66];

console.log('LSD Radix Sort:', radixSort(arr)); // [2, 24, 45, 66, 75, 90, 170, 802]
console.log('MSD Radix Sort:', radixSortMSD(arr)); // [2, 24, 45, 66, 75, 90, 170, 802]

const withNegatives = [170, -45, 75, -90, 802, 24, -2, 66];
console.log('With negatives:', radixSortWithNegatives(withNegatives));

const strings = ['apple', 'pie', 'about', 'cat', 'zoo', 'able'];
console.log('String sort:', radixSortStrings(strings));

const floats = [3.14, 2.71, 1.41, 2.23, 3.16];
console.log('Float sort:', radixSortFloat(floats));

console.log('Base comparison:', compareRadixBases(arr));

module.exports = { 
    radixSort, 
    radixSortMSD, 
    radixSortWithNegatives,
    radixSortStrings,
    radixSortFloat,
    radixSortInPlace
};
