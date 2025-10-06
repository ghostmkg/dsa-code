/**
 * Performs a linear search on an array to find the index of a target element.
 *
 * @param arr The array to search through.
 * @param target The element to search for.
 * @returns The index of the target element if found; otherwise, returns -1.
 */
function linearSearch<T>(arr: T[], target: T): number {
  // Iterate through the array from the start (index 0) to the end.
  for (let i = 0; i < arr.length; i++) {
    // Check if the current element is equal to the target.
    if (arr[i] === target) {
      // If a match is found, return its index immediately.
      return i;
    }
  }

  // If the loop completes without finding the target, return -1.
  return -1;
}

// --- Usage Example ---

const numbers: number[] = [10, 5, 20, 8, 15];
const targetNumber: number = 20;

const resultIndexNumber: number = linearSearch(numbers, targetNumber);

if (resultIndexNumber !== -1) {
  console.log(`Target ${targetNumber} found at index: ${resultIndexNumber}`); // Output: Target 20 found at index: 2
} else {
  console.log(`Target ${targetNumber} not found in the array.`);
}

// Example with a string array
const names: string[] = ["Alice", "Bob", "Charlie", "David"];
const targetName: string = "Bob";

const resultIndexString: number = linearSearch(names, targetName);

if (resultIndexString !== -1) {
  console.log(`Target ${targetName} found at index: ${resultIndexString}`); // Output: Target Bob found at index: 1
} else {
  console.log(`Target ${targetName} not found in the array.`);
}
