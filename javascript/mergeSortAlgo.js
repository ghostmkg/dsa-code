/**
 * Merge two sorted arrays into one sorted array
 */
function merge(left, right) {
  let result = [];
  let i = 0;
  let j = 0;

  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) {
      result.push(left[i]);
      i++;
    } else {
      result.push(right[j]);
      j++;
    }
  }

  // Add any remaining elements
  return result.concat(left.slice(i)).concat(right.slice(j));
}

/**
 * Merge Sort Algorithm
 * @param {number[]} arr - The array to sort
 * @returns {number[]} Sorted array
 */
function mergeSort(arr) {
  if (arr.length <= 1) {
    return arr; // Base case
  }

  const mid = Math.floor(arr.length / 2);

  const left = mergeSort(arr.slice(0, mid));
  const right = mergeSort(arr.slice(mid));

  return merge(left, right);
}

// Example usage:
const nums = [38, 27, 43, 3, 9, 82, 10];
console.log("Original:", nums);
console.log("Sorted:", mergeSort(nums));
