/* Question: Every element appears twice except for one unique element that appears only once.
    Example - 
    Input: nums = [4,1,2,1,2]
    Output: 4
*/

var singleNumber = function (nums) {
  let unique = nums[0]; // start with the first element
  for (let i = 1; i < nums.length; i++) {
    unique = unique ^ nums[i]; // XOR with every other element
  }
  return unique; // the unique number
};

console.log(singleNumber([4, 1, 2, 4, 1, 2, 3])); // Output: 3
