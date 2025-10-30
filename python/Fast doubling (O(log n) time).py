class Solution:
    def fib(self, n: int) -> int:
        # returns (F(n), F(n+1))
        def fast_doubling(k: int):
            if k == 0:
                return (0, 1)
            a, b = fast_doubling(k // 2)
            c = a * (2 * b - a)          # F(2m) = F(m) * (2*F(m+1) − F(m))
            d = a * a + b * b            # F(2m+1) = F(m)^2 + F(m+1)^2
            if k % 2 == 0:
                return (c, d)
            else:
                return (d, c + d)

        return fast_doubling(n)[0]

# test
if __name__ == "__main__":
    s = Solution()
    print(s.fib(50))  # 12586269025
