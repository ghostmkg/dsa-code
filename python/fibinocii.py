# LeetCode 509 style
class Solution:
    def fib(self, n: int) -> int:
        if n < 2:
            return n
        a, b = 0, 1
        for _ in range(2, n+1):
            a, b = b, a + b
        return b

# quick tests
if __name__ == "__main__":
    s = Solution()
    print(s.fib(0))  # 0
    print(s.fib(1))  # 1
    print(s.fib(10)) # 55
 