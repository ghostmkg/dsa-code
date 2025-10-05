// Binary Search : Given a sorted array and a target value, return the index if the target is found. If not, return -1.
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

function binarySearch(nums, target) {
  let left = 0;
  let right = nums.length - 1;
  while (left <= right) {
    // Find the middle element
    let mid = Math.floor((left + right) / 2);
    // If the middle element is the target, return its index
    if (nums[mid] === target) {
      return mid;
      // If the middle element is less than the target, search the right half
    } else if (nums[mid] < target) {
      left = mid + 1;
      // If the middle element is greater than the target, search the left half
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

console.log(binarySearch([-3, -1, 2, 4, 5, 9, 12], 9)); // Output: 5
