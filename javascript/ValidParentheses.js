// Time: O(n), Space: O(n)
var isValid = function (s) {
  const stack = [];
  const map = { ")": "(", "}": "{", "]": "[" };
  for (let char of s) {
    if (char in map) {
      if (stack.length === 0 || stack.pop() !== map[char]) return false;
    } else {
      stack.push(char);
    }
  }
  return stack.length === 0;
};
