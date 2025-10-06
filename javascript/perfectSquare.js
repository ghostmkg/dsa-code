/*
Question:
Check whether a given number is a perfect square 
(using Binary Search instead of Math.sqrt).

Time Complexity: O(log n)
Space Complexity: O(1)

Examples:
Input: num = 16
Output: true
Explanation: 4 * 4 = 16 → perfect square

Input: num = 14
Output: false
Explanation: There is no integer x such that x * x = 14
*/

var isPerfectSquare = function (num) {
  // Special case: 1 is a perfect square
  if (num === 1) return true;

  // Search space: from 2 up to num/2
  let low = 2;
  let high = Math.floor(num / 2);

  while (low <= high) {
    let mid = Math.floor((low + high) / 2);
    let sq = mid * mid;

    if (sq === num)
      return true; // found exact square
    else if (sq > num)
      high = mid - 1; // mid^2 too large → search left
    else low = mid + 1; // mid^2 too small → search right
  }

  // No perfect square found
  return false;
};

// Example runs:
console.log(isPerfectSquare(16)); // true  (4 * 4 = 16)
console.log(isPerfectSquare(14)); // false (no integer square root)
console.log(isPerfectSquare(1)); // true  (1 * 1 = 1)
