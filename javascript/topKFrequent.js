// Time: O(n log k), Space: O(n)
var topKFrequent = function (nums, k) {
  const freqMap = new Map();
  nums.forEach((num) => freqMap.set(num, (freqMap.get(num) || 0) + 1));

  const heap = [...freqMap.entries()].sort((a, b) => b[1] - a[1]);
  return heap.slice(0, k).map((entry) => entry[0]);
};
