// Time: O(n), Space: O(1)
var maxSubArray = function (nums) {
  let maxSoFar = nums[0];
  let current = nums[0];
  for (let i = 1; i < nums.length; i++) {
    current = Math.max(nums[i], current + nums[i]);
    maxSoFar = Math.max(maxSoFar, current);
  }
  return maxSoFar;
};
