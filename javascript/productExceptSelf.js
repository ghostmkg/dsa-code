// Time: O(n), Space: O(1) (excluding output array)
var productExceptSelf = function (nums) {
  let res = Array(nums.length).fill(1);
  let left = 1,
    right = 1;

  for (let i = 0; i < nums.length; i++) {
    res[i] *= left;
    left *= nums[i];
  }

  for (let i = nums.length - 1; i >= 0; i--) {
    res[i] *= right;
    right *= nums[i];
  }

  return res;
};
