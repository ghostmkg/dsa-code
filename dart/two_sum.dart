// LeetCode Problem: Two Sum
// Author: Abhishek Chauhan
// Language: Dart

class Solution {
  List<int> twoSum(List<int> nums, int target) {
    final Map<int, int> seen = {};

    for (int i = 0; i < nums.length; i++) {
      final complement = target - nums[i];

      if (seen.containsKey(complement)) {
        return [seen[complement]!, i];
      }

      seen[nums[i]] = i;
    }

    return [];
  }
}

void main() {
  final solution = Solution();
  final nums = [2, 7, 11, 15];
  final target = 9;

  final result = solution.twoSum(nums, target);
  print("Indices: $result");
}
