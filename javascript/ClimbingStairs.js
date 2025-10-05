// Time: O(n), Space: O(1)
var climbStairs = function (n) {
  if (n <= 2) return n;
  let first = 1,
    second = 2;
  for (let i = 3; i <= n; i++) {
    let third = first + second;
    first = second;
    second = third;
  }
  return second;
};
