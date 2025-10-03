/**
 * Merges two sorted subarrays into one sorted array.
 * @param left The left sorted array.
 * @param right The right sorted array.
 * @returns The merged and sorted array.
 */
function merge<T>(left: T[], right: T[]): T[] {
  const result: T[] = [];
  let i = 0; // Index for the left array
  let j = 0; // Index for the right array

  // Compare elements from both arrays and push the smaller one to the result
  while (i < left.length && j < right.length) {
    if (left[i] < right[j]) {
      result.push(left[i]);
      i++;
    } else {
      result.push(right[j]);
      j++;
    }
  }

  // Append any remaining elements (one of these loops will run)
  return result.concat(left.slice(i)).concat(right.slice(j));
}

/**
 * Sorts an array using the Merge Sort algorithm.
 * @param arr The array to sort.
 * @returns The fully sorted array.
 */
function mergeSort<T>(arr: T[]): T[] {
  // Base case: arrays with 0 or 1 element are already sorted
  if (arr.length <= 1) {
    return arr;
  }

  // 1. Divide the array into two halves (left and right)
  const mid = Math.floor(arr.length / 2);
  const left = arr.slice(0, mid);
  const right = arr.slice(mid);

  // 2. Recursively sort both halves
  const sortedLeft = mergeSort(left);
  const sortedRight = mergeSort(right);

  // 3. Merge the sorted halves
  return merge(sortedLeft, sortedRight);
}

// --- Usage Example ---
const unsortedArray = [38, 27, 43, 3, 9, 82, 10];
const sortedArray = mergeSort(unsortedArray);
console.log("\n--- Merge Sort ---");
console.log(`Unsorted: [${unsortedArray.join(", ")}]`);
console.log(`Sorted:   [${sortedArray.join(", ")}]`);
// Expected Output: [3, 9, 10, 27, 38, 43, 82]
